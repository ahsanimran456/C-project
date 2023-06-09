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

// Function to place an order
void placeOrder() {
    Order newOrder;

    printf("Enter dish name: ");
    scanf("%s", newOrder.dishName);

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

    char choice;
    printf("Do you want to edit this order? (Y/N): ");
    scanf(" %c", &choice);

    if (choice == 'Y' || choice == 'y') {
        printf("Enter new dish name: ");
        scanf("%s", newOrder.dishName);

        printf("Enter new price: ");
        scanf("%f", &newOrder.price);

        orders[numOrders - 1] = newOrder;

        printf("Order updated successfully.\n");
        printf("Updated Order Details\n");
        printf("-------------------\n");
        printf("Order Number: %d\n", newOrder.orderNumber);
        printf("Dish Name: %s\n", newOrder.dishName);
        printf("Price: %.2f\n", newOrder.price);
        printf("-------------------\n");
    } else {
        printf("Order not edited.\n");
    }
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
        printf("3. View Orders\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displaySchedule();
                break;
            case 2:
                placeOrder();
                break;
            case 3:
                displayOrders();
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 4);

    return 0;
}
