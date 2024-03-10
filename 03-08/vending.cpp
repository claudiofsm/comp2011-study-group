#include <iostream>

using namespace std;

const int NUM_DRINK_TYPES = 4;
const int NUM_COIN_TYPES = 6;
const int MAX_COINS = 100;
const int COIN_VALUES[NUM_COIN_TYPES] = { 500, 200, 100, 50, 20, 10 };

void printInvalidInput() {
    cerr << "Invalid input. Please enter again." << endl;
}

int getChoice() {
    string input = "";
    cin >> input;

    if (input.empty()) {
        return -1;
    }

    for (unsigned int i = 0; i < input.length(); i++) {
        if (!isdigit(input.at(i))) {
            return -1;
        }
    }

    return stoi(input);
}

void printStock(string names[NUM_DRINK_TYPES], 
                int quantity[NUM_DRINK_TYPES], 
                int price[NUM_DRINK_TYPES]) {
    cout << "Available drinks:" << endl;
    for (int i = 0; i < NUM_DRINK_TYPES; i++) {
        cout 
            << '[' << i + 1 << "] " 
            << names[i] << " (" << quantity[i] << " left): "
            <<"$" << price[i] / 100 << "." << (price[i] % 100) / 10
            << endl;
    }
}

int getDrinkType(string names[NUM_DRINK_TYPES], 
                 int quantity[NUM_DRINK_TYPES], 
                 int price[NUM_DRINK_TYPES]) {
    int type = -1;
    
    while (type < 0) {
        printStock(names, quantity, price);

        cout << "Please enter a number to select the drink: ";
        int choice = getChoice();
        if (choice <= 0 || choice > NUM_DRINK_TYPES) {
            printInvalidInput();
        } else {
            type = choice - 1;
        }
    }

    return type;
}

void printAmountDue(int amount) {
    cout << "$" << amount / 100 << "." << (amount % 100) / 10 << " remaining. Accepting coins:" << endl;
    cout 
        << "[1] $5" << endl
        << "[2] $2" << endl
        << "[3] $1" << endl
        << "[4] $0.5" << endl
        << "[5] $0.2" << endl
        << "[6] $0.1" << endl
        << "[0] Cancel" << endl;
}

void printChanges(string reason, int changes[NUM_COIN_TYPES]) {
    cout << "Purchase " << reason << ". Changes: $";

    bool none = true;
    for (int i = 0; i < NUM_COIN_TYPES; i++) {
        if (changes[i] > 0) {
            none = false;
            break;
        }
    }

    if (!none) {
        for (int i = 0; i < 3; i++) {
            if (changes[i] > 0) {
                cout << " $" << COIN_VALUES[i] / 100 << " x " << changes[i] << ",";
            }
        }
        for (int j = 3; j < NUM_COIN_TYPES; j++) {
            if (changes[j] > 0) {
                cout << " $0." << COIN_VALUES[j] / 10 << " x " << changes[j] << ",";
            }
        }
    }

    cout << "\b \b";  // eat the last character

    if (none) {
        cout << "none";
    }

    cout << endl;
}

int getCoinTypeInserted(int due) {
    int type = -2;

    while (type < -1) {
        printAmountDue(due);

        cout << "Please enter a number to insert a coin: ";
        int choice = getChoice();
        if (choice < 0 || choice > NUM_COIN_TYPES) {
            printInvalidInput();
        } else {
            type = choice - 1;
        }
    }

    return type;
}

void deliverChanges(int coins[NUM_COIN_TYPES], 
                    int amount,
                    int changes[NUM_COIN_TYPES]) {
    int remaining = amount;
    for (int i = 0; i < NUM_COIN_TYPES; i++) {
        while (COIN_VALUES[i] <= remaining) {
            coins[i]--;
            changes[i]++;
            remaining -= COIN_VALUES[i];
        }
    }
}

int getTotalCoinsInStorage(int coins[NUM_COIN_TYPES]) {
    int total = 0;
    for (int i = 0; i < NUM_COIN_TYPES; i++) {
        total += coins[i];
    }
    return total;
}

bool isCoinStorageFull(int coins[NUM_COIN_TYPES]) {
    return getTotalCoinsInStorage(coins) >= MAX_COINS;
}

bool isCoinStorageLow(int coins[NUM_COIN_TYPES]) {
    // This is a safe set of coins which can deliver changes
    // for any amount under $5.
    return coins[0] < 1     // $5
        || coins[1] < 2     // $2
        || coins[2] < 1     // $1
        || coins[3] < 1     // $0.5
        || coins[4] < 2     // $0.2
        || coins[5] < 1;    // $0.1
}

void printCoinStorage(int coins[NUM_COIN_TYPES]) {
    cout << "coins: {";
    for (int i = 0; i < NUM_COIN_TYPES; i++) {
        cout << " " << coins[i] << ", ";
    }
    cout << "}" << endl;
}

int main() {
    int stock[NUM_DRINK_TYPES] = { 20, 20, 20, 20 };
    string names[NUM_DRINK_TYPES] = { "Coke", "Coffee", "Tea", "Water" };
    int price[NUM_DRINK_TYPES] = { 400, 850, 600, 300 };
    int coins[NUM_COIN_TYPES] = { 10, 10, 10, 10, 10, 10 };

    bool exit = false;
    while (!exit) {
        if (isCoinStorageFull(coins)) {
            cout << "Coin storage full. Machine shuts down." << endl;
            exit = true;
            continue;
        }
        if (isCoinStorageLow(coins)) {
            cout << "Coin storage low. Machine shuts down." << endl;
            exit = true;
            continue;
        }

        printCoinStorage(coins);

        int drinkType = getDrinkType(names, stock, price);
        int amountDue = price[drinkType];
        bool cancelled = false;
        while (amountDue > 0 && !cancelled) {
            int coinType = getCoinTypeInserted(amountDue);
            if (-1 == coinType) {
                // cancel purchase
                cancelled = true;
                continue;
            }

            int totalCoins = getTotalCoinsInStorage(coins);
            
            if (totalCoins < MAX_COINS - 1) {
                coins[coinType] += 1;
                amountDue -= COIN_VALUES[coinType];
            }
        }

        int changes[NUM_COIN_TYPES] = { 0, 0, 0, 0, 0, 0 };
        string reason = cancelled ? "cancelled" : "completed";
        if (cancelled) {
            deliverChanges(coins, price[drinkType] - amountDue, changes);
        } else {
            stock[drinkType] -= 1;
            if (amountDue < 0) {
                deliverChanges(coins, 0 - amountDue, changes);
            }
        }

        printChanges(reason, changes);
   }

    return 0;
}