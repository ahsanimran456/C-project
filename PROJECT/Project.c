// #include <stdio.h>
// #include <string.h>

// #define MAX_ORDERS 100

// // Structure to store an order
// typedef struct {
//     int orderNumber;
//     char dishName[100];
//     float price;
// } Order;

// // Global array to store orders
// Order orders[MAX_ORDERS];
// int numOrders = 0;

// // Function to display the restaurant schedule
// void displaySchedule() {
//     printf("Restaurant Schedule\n");
//     printf("-------------------\n");
//     printf("Monday: 8 AM - 10 PM\n");
//     printf("Tuesday: 8 AM - 10 PM\n");
//     printf("Wednesday: 8 AM - 10 PM\n");
//     printf("Thursday: 8 AM - 10 PM\n");
//     printf("Friday: 8 AM - 11 PM\n");
//     printf("Saturday: 9 AM - 11 PM\n");
//     printf("Sunday: 9 AM - 10 PM\n");
//     printf("-------------------\n");
// }

// // Function to place an order
// void placeOrder() {
//     Order newOrder;

//     printf("Enter dish name: ");
//     scanf("%s", newOrder.dishName);

//     printf("Enter price: ");
//     scanf("%f", &newOrder.price);

//     newOrder.orderNumber = numOrders + 1;
//     orders[numOrders] = newOrder;
//     numOrders++;

//     printf("Order placed successfully.\n");

//     printf("Order Details\n");
//     printf("-------------\n");
//     printf("Order Number: %d\n", newOrder.orderNumber);
//     printf("Dish Name: %s\n", newOrder.dishName);
//     printf("Price: %.2f\n", newOrder.price);
//     printf("-------------------\n");
// }

// // Function to display all orders
// void displayOrders() {
//     printf("Orders\n");
//     printf("------\n");
//     if (numOrders == 0) {
//         printf("No orders found.\n");
//     } else {
//         for (int i = 0; i < numOrders; i++) {
//             printf("Order Number: %d\n", orders[i].orderNumber);
//             printf("Dish Name: %s\n", orders[i].dishName);
//             printf("Price: %.2f\n", orders[i].price);
//             printf("-------------------\n");
//         }
//     }
// }

// int main() {
//     int choice;

//     do {
//         printf("CRUD System\n");
//         printf("-----------\n");
//         printf("1. View Restaurant Schedule\n");
//         printf("2. Place an Order\n");
//         printf("3. View Orders\n");
//         printf("4. Exit\n");
//         printf("Enter your choice: ");
//         scanf("%d", &choice);

//         switch (choice) {
//             case 1:
//                 displaySchedule();
//                 break;
//             case 2:
//                 placeOrder();
//                 break;
//             case 3:
//                 displayOrders();
//                 break;
//             case 4:
//                 printf("Exiting program.\n");
//                 break;
//             default:
//                 printf("Invalid choice. Please try again.\n");
//                 break;
//         }
//     } while (choice != 4);

//     return 0;
// }


#include <stdio.h>
#include <string.h>

#define MAX_ORDERS 100

// Structure to store an order
typedef struct {
    int orderNumber;
    char dishName[100];
    float price;
} Order;

// Global array to store orders
Order orders[MAX_ORDERS];
int numOrders = 0;

// Function to display the restaurant schedule
void displaySchedule() {
    printf("Restaurant Schedule\n");
    printf("-------------------\n");
    printf("Monday: 8 AM - 10 PM\n");
    printf("Tuesday: 8 AM - 10 PM\n");
    printf("Wednesday: 8 AM - 10 PM\n");
    printf("Thursday: 8 AM - 10 PM\n");
    printf("Friday: 8 AM - 11 PM\n");
    printf("Saturday: 9 AM - 11 PM\n");
    printf("Sunday: 9 AM - 10 PM\n");
    printf("-------------------\n");
}

// Function to display the restaurant menu
void displayMenu() {
    printf("*************************************************************************\n");
    printf("Description-------------------Item Name--------------------Price(tk)\n");
    printf("\n");
    printf("1.--------------------------- Burger ---------------------- $5.99\n");
    printf("2.--------------------------- Pizza ----------------------- $8.99\n");
    printf("3.--------------------------- Pasta ------------------------ $7.99\n");
    printf("4.--------------------------- Salad ------------------------ $6.99\n");
    printf("5.--------------------------- Sandwich ------------------------ $4.99\n");
    printf("\n");
    printf("*************************************************************************\n");
}

// Function to check if a dish name exists in the menu
int isDishAvailable(const char* dishName) {
    if (strcmp(dishName, "Burger") == 0 ||
        strcmp(dishName, "Pizza") == 0 ||
        strcmp(dishName, "Pasta") == 0 ||
        strcmp(dishName, "Salad") == 0 ||
        strcmp(dishName, "Sandwich") == 0) {
        return 1;
    }
    return 0;
}

// Function to place an order
void placeOrder() {
    Order newOrder;

    printf("Enter dish name: ");
    scanf("%s", newOrder.dishName);

    // Check if the dish name exists in the menu
    if (!isDishAvailable(newOrder.dishName)) {
        printf("Sorry, the selected dish is unavailable.\n");
        return;
    }

    printf("Enter price: ");
    scanf("%f", &newOrder.price);

    newOrder.orderNumber = numOrders + 1;
    orders[numOrders] = newOrder;
    numOrders++;

    printf("Order placed successfully.\n");

    printf("Order Details\n");
    printf("-------------\n");
    printf("Order Number: %d\n", newOrder.orderNumber);
    printf("Dish Name: %s\n", newOrder.dishName);
    printf("Price: %.2f\n", newOrder.price);
    printf("-------------------\n");
}

// Function to delete an order
void deleteOrder(int orderNumber) {
    int orderIndex = -1;

    // Find the index of the order to delete
    for (int i = 0; i < numOrders; i++) {
        if (orders[i].orderNumber == orderNumber) {
            orderIndex = i;
            break;
        }
    }

    if (orderIndex == -1) {
        printf("Order not found.\n");
        return;
    }

    // Shift orders to remove the deleted order
    for (int i = orderIndex; i < numOrders - 1; i++) {
        orders[i] = orders[i + 1];
    }

    numOrders--;

    printf("Order deleted successfully.\n");
}

// Function to display all orders
void displayOrders() {
    printf("Orders\n");
    printf("------\n");
    if (numOrders == 0) {
        printf("No orders found.\n");
    } else {
        for (int i = 0; i < numOrders; i++) {
            printf("Order Number: %d\n", orders[i].orderNumber);
            printf("Dish Name: %s\n", orders[i].dishName);
            printf("Price: %.2f\n", orders[i].price);
            printf("-------------------\n");
        }
    }
}

int main() {
    int choice;

    do {
        printf("CRUD System\n");
        printf("-----------\n");
        printf("1. View Restaurant Schedule\n");
        printf("2. Place an Order\n");
        printf("3. Delete an Order\n");
        printf("4. View Orders\n");
        printf("5. View Menu\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displaySchedule();
                break;
            case 2:
                placeOrder();
                break;
            case 3: {
                int orderNumber;
                printf("Enter the order number to delete: ");
                scanf("%d", &orderNumber);
                deleteOrder(orderNumber);
                break;
            }
            case 4:
                displayOrders();
                break;
            case 5:
                displayMenu();
                break;
            case 6:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 6);

    return 0;
}
