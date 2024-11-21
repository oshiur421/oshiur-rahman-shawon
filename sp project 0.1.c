
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structures
typedef struct {
    int id;
    char name[50];
    float price;
} Dish;

typedef struct {
    int id;
    int dishId;
    int quantity;
} Order;

// Global variables
Dish dishes[100];
Order orders[100];
int dishCount = 0, orderCount = 0;
float totalSales = 0;

// Function prototypes
void addDish();
void modifyDish();
void deleteDish();
void placeOrder();
void cancelOrder();
void displayDishes();
void displayOrders();
void salesReport();

int main() {
    int choice;
    do {
        printf("\n=== Restaurant Management System ===\n");
        printf("1. Add New Dish\n");
        printf("2. Modify Existing Dish\n");
        printf("3. Delete Dish\n");
        printf("4. Place Order\n");
        printf("5. Cancel Order\n");
        printf("6. Display All Dishes\n");
        printf("7. Display All Orders\n");
        printf("8. Sales Report\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addDish(); break;
            case 2: modifyDish(); break;
            case 3: deleteDish(); break;
            case 4: placeOrder(); break;
            case 5: cancelOrder(); break;
            case 6: displayDishes(); break;
            case 7: displayOrders(); break;
            case 8: salesReport(); break;
            case 9: printf("Exiting...\n"); break;
            default: printf("Invalid choice! Try again.\n");
        }
    } while (choice != 9);
    return 0;
}

void addDish() {
    printf("Enter dish ID: ");
    scanf("%d", &dishes[dishCount].id);
    printf("Enter dish name: ");
    scanf(" %[^\n]", dishes[dishCount].name);
    printf("Enter dish price: ");
    scanf("%f", &dishes[dishCount].price);
    dishCount++;
    printf("Dish added successfully!\n");
}

void modifyDish() {
    int id, found = 0;
    printf("Enter dish ID to modify: ");
    scanf("%d", &id);
    for (int i = 0; i < dishCount; i++) {
        if (dishes[i].id == id) {
            printf("Enter new name: ");
            scanf(" %[^\n]", dishes[i].name);
            printf("Enter new price: ");
            scanf("%f", &dishes[i].price);
            found = 1;
            printf("Dish modified successfully!\n");
            break;
        }
    }
    if (!found) printf("Dish not found!\n");
}

void deleteDish() {
    int id, found = 0;
    printf("Enter dish ID to delete: ");
    scanf("%d", &id);
    for (int i = 0; i < dishCount; i++) {
        if (dishes[i].id == id) {
            for (int j = i; j < dishCount - 1; j++) {
                dishes[j] = dishes[j + 1];
            }
            dishCount--;
            found = 1;
            printf("Dish deleted successfully!\n");
            break;
        }
    }
    if (!found) printf("Dish not found!\n");
}

void placeOrder() {
    int dishId, quantity, found = 0;
    printf("Enter dish ID to order: ");
    scanf("%d", &dishId);
    for (int i = 0; i < dishCount; i++) {
        if (dishes[i].id == dishId) {
            printf("Enter quantity: ");
            scanf("%d", &quantity);
            orders[orderCount].id = orderCount + 1;
            orders[orderCount].dishId = dishId;
            orders[orderCount].quantity = quantity;
            totalSales += dishes[i].price * quantity;
            orderCount++;
            found = 1;
            printf("Order placed successfully!\n");
            break;
        }
    }
    if (!found) printf("Dish not found!\n");
}

void cancelOrder() {
    int id, found = 0;
    printf("Enter order ID to cancel: ");
    scanf("%d", &id);
    for (int i = 0; i < orderCount; i++) {
        if (orders[i].id == id) {
            for (int j = 0; j < dishCount; j++) {
                if (dishes[j].id == orders[i].dishId) {
                    totalSales -= dishes[j].price * orders[i].quantity;
                    break;
                }
            }
            for (int j = i; j < orderCount - 1; j++) {
                orders[j] = orders[j + 1];
            }
            orderCount--;
            found = 1;
            printf("Order cancelled successfully!\n");
            break;
        }
    }
    if (!found) printf("Order not found!\n");
}

void displayDishes() {
    printf("\n=== Dishes ===\n");
    for (int i = 0; i < dishCount; i++) {
        printf("ID: %d, Name: %s, Price: %.2f\n", dishes[i].id, dishes[i].name, dishes[i].price);
    }
}

void displayOrders() {
    printf("\n=== Orders ===\n");
    for (int i = 0; i < orderCount; i++) {
        printf("Order ID: %d, Dish ID: %d, Quantity: %d\n",
               orders[i].id, orders[i].dishId, orders[i].quantity);
    }
}

void salesReport() {
    printf("\n=== Sales Report ===\n");
    printf("Total Sales: %.2f\n", totalSales);
}
