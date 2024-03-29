#include <iostream>

using namespace std;

const int NUM_DRINK_TYPES = 4;
const int NUM_COIN_TYPES = 6;
const int MAX_COINS = 100;
const int COIN_VALUES[NUM_COIN_TYPES] = { 500, 200, 100, 50, 20, 10 };

void printInvalidInput() {
    cerr << "Invalid input. Please enter again." << endl;
}

/**
 * Returns the non-negative integer input user has entered, or -1 if the
 * user input other strings.
 * 
 * @return  a non-negative integer choice, or -1 otherwise
 */
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

/**
 * Prints the current stock level.
 * 
 * @param names  the display name of the drinks
 * @param quantity  the amount left for each type of drinks
 * @param price  the price for each type of drinks 
 */
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

/**
 * Returns the type of drink the user has entered.
 * 
 * @param names  the display name of the drinks
 * @param quantity  the amount left for each type of drinks
 * @param price  the price for each type of drinks 
 * @return zero-based type, or -1 if user has requested to cancel.
 */
int getDrinkType(string names[NUM_DRINK_TYPES], 
                 int quantity[NUM_DRINK_TYPES], 
                 int price[NUM_DRINK_TYPES]) {
    int type = -1;
    
    while (type < 0) {
        printStock(names, quantity, price);

        cout << "Please enter a number to select the drink: ";
        int choice = getChoice();
        if (choice <= 0 || choice > NUM_DRINK_TYPES || quantity[choice - 1] <= 0) {
            printInvalidInput();
        } else {
            type = choice - 1;
        }
    }

    return type;
}

/**
 * Displays the amount due during a purchase. 
 * 
 * @param amount  the amount due in cents. 
 */
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

/**
 * Displays the coin changes.
 * 
 * @param reason  the reason to deliver the changes
 * @param changes an array containing the number of coins corresponding to each coin type
 *                composing the overall changes.
 */
void printChanges(string reason, int changes[NUM_COIN_TYPES]) {
    cout << reason << ". Changes: $";

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

/**
 * Returns the type of the coin inserted.
 * 
 * @param due  the amount due during the purchase
 * @return     zero-based type of the inserted coin, or -1 if the input is invalid
 */
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

/**
 * Delivers changes to the user.
 * 
 * @param coins  the new number of different type of coins remaining in the coin storage
 * @param amount the amount of changes in cents
 * @param changes an array containing the number of coins corresponding to each coin type
 *                composing the overall changes.
 */
void deliverChanges(int coins[NUM_COIN_TYPES], 
                    int amount,
                    int changes[NUM_COIN_TYPES]) {
    int remaining = amount;
    for (int i = 0; i < NUM_COIN_TYPES; i++) {
        while (COIN_VALUES[i] <= remaining) {
            coins[i]--;
            changes[i]++;
            remaining -= COIN_VALUES[i];
            if (remaining <= 0) {
                return;
            }
        }
    }
}

/**
 * Resets the number of different types of coins in the changes to zero.
 */
void clearChanges(int changes[NUM_COIN_TYPES]) {
    for (int i = 0; i < NUM_COIN_TYPES; i++) {
        changes[i] = 0;
    }
}

/**
 * Returns the number of coins in the storage.
 * 
 * @param coins  the number of different types of coins
 * @return   the total number of conis
 */
int getTotalCoinsInStorage(int coins[NUM_COIN_TYPES]) {
    int total = 0;
    for (int i = 0; i < NUM_COIN_TYPES; i++) {
        total += coins[i];
    }
    return total;
}

/**
 * Determines whether the coin storage is full.
 *
 * @param coins  the number of different types of coins
 * @return   true if full, false otherwise
*/
bool isCoinStorageFull(int coins[NUM_COIN_TYPES]) {
    return getTotalCoinsInStorage(coins) >= MAX_COINS;
}

/**
 * Determines whether the number of different types of coins in the storage
 * is low, i.e. may not be able to deliver changes for some amount.
 *
 * @param coins  the number of different types of coins
 * @return   true if storage is low, false otherwise
*/
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

/*
void printCoinStorage(int coins[NUM_COIN_TYPES]) {
    cout << "coins: {";
    for (int i = 0; i < NUM_COIN_TYPES; i++) {
        cout << " " << coins[i] << ", ";
    }
    cout << "}" << endl;
}
*/

int main() {
    int stock[NUM_DRINK_TYPES] = { 20, 20, 20, 20 };
    string names[NUM_DRINK_TYPES] = { "Coke", "Coffee", "Tea", "Water" };
    int price[NUM_DRINK_TYPES] = { 400, 850, 600, 300 };
    int coins[NUM_COIN_TYPES] = { 10, 10, 10, 10, 10, 10 };
    int changes[NUM_COIN_TYPES] = { 0, 0, 0, 0, 0, 0 };

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

        // printCoinStorage(coins);

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

            coins[coinType] += 1;
            amountDue -= COIN_VALUES[coinType];
            
            if (isCoinStorageFull(coins) && amountDue > 0) {
                // refund last inserted coin
                amountDue += COIN_VALUES[coinType];
                deliverChanges(coins, COIN_VALUES[coinType], changes);
                printChanges("Coin storage full", changes);
                clearChanges(changes);
            }
        }

        if (cancelled) {
            deliverChanges(coins, price[drinkType] - amountDue, changes);
        } else {
            stock[drinkType] -= 1;
            if (amountDue < 0) {
                deliverChanges(coins, 0 - amountDue, changes);
            }
        }

        printChanges(cancelled ? "Purchase cancelled" : "Purchase completed", changes);
        clearChanges(changes);
   }

    return 0;
}