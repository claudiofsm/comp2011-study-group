# Vending Machine

In this exercise we are going to simulate the operations of a vending machine.
A user buys drinks from the machine using coins, and the machine delivers the 
requested drink with coin changes (if any).

## Configuration of the Machine

- There are 4 types of drinks being sold: coke, coffee, tea and water, with 
price $4, $8.5, $6 and $3 respectively.
- For each of the 4 types, the machine can hold a total of 20 items. That means
there are 80 items in the machine when the stock is fully filled.
- The machine accepts the following coins: $5, $2, $1, $0.5, $0.2, $0.1.
- The machine can store a maximum of 100 coins, independent of the type.

## Behaviour of the Machine

- When the machine starts, the stock is refilled to maximum. The coin storage 
contains 10 coins for each of the acceptable types.
- To purchase a drink, a user is required to select one desired drink before 
inserting coins.
- After selecting the desired drink, the purchase is considered started. A user
is then required to insert coins one by one.
- After each coin insertion:
    - if the accumulated amount is larger than the price, the purchase is 
    completed. The requested drink will be delivered, and the changes will be 
    returned.
    - if the accumulated amount is equal to the price, the purchase is 
    completed. The requested drink will be delivered. If the coin storage is 
    full, the machine will shut down.
    - if the accumulated amount is less than the price, the purchase is not 
    completed. No drink will be delivered. If the coin storage is not yet full,
    the user is required to insert the next coin. Otherwise, the newly inserted
    coin will be returned to the user.
- After a purchase has been started, the user can cancel the purchase. If a
cancellation is made, the machine will refund the inserted amount (if any) to 
the user, and no drink will be delivered. The machine then accepts new 
purchases again.
- If any kind of drinks is out of stock, the machine will not allow users to 
select it for purchase.
- To prevent failure of returning changes to user after successful purchases, 
when the different types of coins in the coin storage falls below a certain
threshold _(try to figure it out! :P)_, the machine will shut down.

## Program Input & Output

You are required to write a C++ program to simulate the operations of the
vending machine described above. The input and output of the program are 
specified below.

The program displays the following menu to prompt user for purchases:
```
Available drinks:
[1] Coke (20 left): $4
[2] Coffee (20 left): $8.5
[3] Tea (20 left): $6
[4] Water (20 left): $3
Please enter a number to select the drink:
```
Users will enter the corresponding number of the drink to start purchases. If 
an invalid input is detected, an error message is displayed and the menu is 
printed again:
```
Invalid input. Please enter again.
Available drinks:
[1] Coke (20 left): $4
[2] Coffee (20 left): $8.5
[3] Tea (20 left): $6
[4] Water (20 left): $3
Please enter a number to select the drink: 
```

Assume the user selected to purchase coffee, the program displays the amount 
due and prompt the user to insert coins like below:
```
$8.5 remaining. Accepting coins:
[1] $5
[2] $2
[3] $1
[4] $0.5
[5] $0.2
[6] $0.1
[0] Cancel
Please enter a number to insert a coin:
```

The program displays the amount due and prompt the user to insert more coins:
```
$3.5 remaining. Accepting coins:
[1] $5
[2] $2
[3] $1
[4] $0.5
[5] $0.2
[6] $0.1
[0] Cancel
Please enter a number to insert a coin:
```

If a user cancelled the purchase, the total amount inserted (assuming $7.5) 
will be refunded:
```
Purchase cancelled. Changes: $5 x 1, $2 x 1, $0.5 x 1
Available drinks:
[1] Coke (20 left): $4
[2] Coffee (19 left): $8.5
[3] Tea (20 left): $6
[4] Water (20 left): $3
Please enter a number to select the drink: 
```

When a purchase is completed, the changes amount and updated stock is 
displayed:
```
Purchase completed. Changes: $1 x 1, $0.5 x 1
Available drinks:
[1] Coke (20 left): $4
[2] Coffee (19 left): $8.5
[3] Tea (20 left): $6
[4] Water (20 left): $3
Please enter a number to select the drink: 
```

If the user has inserted the exact amount of the price, i.e. no changes, the
updated stock is displayed:
```
Purchase completed. Changes: none
Available drinks:
[1] Coke (20 left): $4
[2] Coffee (19 left): $8.5
[3] Tea (20 left): $6
[4] Water (20 left): $3
Please enter a number to select the drink: 
```

When coin storage is full during a purchase and the newly inserted coin is 
returned, a message is displayed:
```
Coin storage full. Changes: $5 x 1
$8.5 remaining. Accepting coins:
[1] $5
[2] $2
[3] $1
[4] $0.5
[5] $0.2
[6] $0.1
[0] Cancel
Please enter a number to insert a coin:
```

When coin storage is full after a successful purchase, the following message is
displayed and the machine shuts down:
```
Coin storage full. Machine shuts down.
```

When coin storage is low, the following message is displayed and the machine 
shuts down:
```
Coin storage low. Machine shuts down.
```

## Sample Program Output

```
Available drinks:
[1] Coke (20 left): $4
[2] Coffee (20 left): $8.5
[3] Tea (20 left): $6
[4] Water (20 left): $3
Please enter a number to select the drink: 2
$8.5 remaining. Accepting coins:
[1] $5
[2] $2
[3] $1
[4] $0.5
[5] $0.2
[6] $0.1
[0] Cancel
Please enter a number to insert a coin: 1
$3.5 remaining. Accepting coins:
[1] $5
[2] $2
[3] $1
[4] $0.5
[5] $0.2
[6] $0.1
[0] Cancel
Please enter a number to insert a coin: 9
Invalid input. Please enter again.
$3.5 remaining. Accepting coins:
[1] $5
[2] $2
[3] $1
[4] $0.5
[5] $0.2
[6] $0.1
[0] Cancel
Please enter a number to insert a coin: 2
$1.5 remaining. Accepting coins:
[1] $5
[2] $2
[3] $1
[4] $0.5
[5] $0.2
[6] $0.1
[0] Cancel
Please enter a number to insert a coin: 1
Purchase completed. Changes: $2 x 1, $1 x 1, $0.5 x 1
Available drinks:
[1] Coke (20 left): $4
[2] Coffee (19 left): $8.5
[3] Tea (20 left): $6
[4] Water (20 left): $3
Please enter a number to select the drink: 
```
