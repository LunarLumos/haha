# hahaa

For The Funnn !
Sure! Here's the **full explanation** of the code, presented in a way that covers every part of the program in simple terms.

---

## **Restaurant Management System: Full Explanation**

This program is a simple **Restaurant Management System** written in C. It allows both **admins** and **customers** to interact with a restaurant's dish and order system.

### **1. Libraries Used**
```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
```

- **`#include <stdio.h>`**: This library is used for standard input/output operations, like printing to the screen (`printf`) and taking user input (`scanf`).
- **`#include <stdlib.h>`**: This library allows us to use functions for system commands (`system()`) and other utility functions like memory allocation or process control.
- **`#include <string.h>`**: This library is used for string operations, such as comparing strings (`strcmp`) and copying strings (`strcpy`).

### **2. File Definitions**

```c
#define DISHES_FILE "dishes.txt"
#define ORDERS_FILE "orders.txt"
#define ADMIN_USERNAME "admin"
#define ADMIN_PASSWORD "password123"
```

- **`DISHES_FILE`**: This defines the filename where the list of dishes is stored (`dishes.txt`).
- **`ORDERS_FILE`**: This defines the filename where orders are stored (`orders.txt`).
- **`ADMIN_USERNAME` and `ADMIN_PASSWORD`**: These are the login credentials for the admin.

### **3. Functions in the Program**

#### **a) `order_exists` Function**

```c
int order_exists(const char *order_id) {
    char command[512];
    snprintf(command, sizeof(command), "grep -q '^%s,' %s", order_id, ORDERS_FILE);
    return system(command) == 0;
}
```

- **Purpose**: This function checks if a specific order exists in the `orders.txt` file.
- It uses the `grep` command to search for the order ID. If found, it returns `1` (true), otherwise `0` (false).

---

#### **b) `cancel_order` Function**

```c
void cancel_order() {
    char order_id[20];
    printf("Enter the Order ID to cancel (e.g., O1, O2, O3):\n");
    scanf("%s", order_id);

    if (!order_exists(order_id)) {
        printf("Error: Order ID %s not found!\n", order_id);
        return;
    }

    char command[512];
    snprintf(command, sizeof(command), "sed -i 's/^%s,.*/%s,*,*,*,*,*,*,*,Canceled/' %s", order_id, order_id, ORDERS_FILE);
    system(command);
    printf("Order %s canceled successfully!\n", order_id);
}
```

- **Purpose**: Allows the admin to cancel an existing order.
- It checks if the order exists using `order_exists`. If the order exists, it uses the `sed` command to update the order's status to "Canceled" in the `orders.txt` file.

---

#### **c) `display_orders` Function**

```c
void display_orders() {
    printf("All Orders:\n");
    char command[512];
    snprintf(command, sizeof(command), "awk -F',' '{print \"Order ID: \"$1\" | Customer: \"$2\" | Dish: \"$6\" | Quantity: \"$7\" | Total: \"$8\" tk | Status: \"$9}' %s", ORDERS_FILE);
    system(command);
}
```

- **Purpose**: Displays all orders stored in the `orders.txt` file.
- It uses the `awk` command to format the output, showing the order ID, customer name, dish, quantity, total cost, and status.

---

#### **d) `display_dishes` Function**

```c
void display_dishes() {
    printf("All available dishes:\n");
    char command[512];
    snprintf(command, sizeof(command), "awk -F',' '{print \"Dish ID: \"$1\" | Name: \"$2\" | Price: \"$4\" tk | Time: \"$5\" min | Description: \"$3}' %s", DISHES_FILE);
    system(command);
}
```

- **Purpose**: Displays all available dishes from the `dishes.txt` file.
- It uses `awk` to format the output and display each dish's ID, name, price, preparation time, and description.

---

#### **e) `search_dishes` Function**

```c
void search_dishes() {
    char search_term[50];
    printf("Enter dish name to search for (part of name):\n");
    scanf(" %[^\n]s", search_term);

    char command[512];
    snprintf(command, sizeof(command), "grep -i '%s' %s | awk -F',' '{print \"Dish ID: \"$1\" | Name: \"$2\" | Price: \"$4\" tk | Time: \"$5\" min | Description: \"$3}'", search_term, DISHES_FILE);
    system(command);
}
```

- **Purpose**: Allows the admin or customer to search for dishes by name or part of the name.
- It uses `grep` to search for the term in the `dishes.txt` file and then uses `awk` to display the dish details.

---

#### **f) `add_dish` Function**

```c
void add_dish() {
    char dish_id[10], dish_name[50], dish_description[100], dish_price[10], dish_prep_time[10];
    printf("Enter Dish ID (e.g., 1, 2, 3):\n");
    scanf("%s", dish_id);
    printf("Enter Dish Name:\n");
    scanf(" %[^\n]s", dish_name);
    printf("Enter Dish Description:\n");
    scanf(" %[^\n]s", dish_description);
    printf("Enter Dish Price (in tk):\n");
    scanf("%s", dish_price);
    printf("Enter Dish Preparation Time (in minutes):\n");
    scanf("%s", dish_prep_time);
    
    char command[512];
    snprintf(command, sizeof(command), "echo \"%s,%s,%s,%s,%s\" >> %s", dish_id, dish_name, dish_description, dish_price, dish_prep_time, DISHES_FILE);
    system(command);

    printf("Dish '%s' added successfully!\n", dish_name);
}
```

- **Purpose**: Allows the admin to add a new dish to the menu.
- It takes the dish details (ID, name, description, price, and preparation time) from the user and appends them to the `dishes.txt` file using the `echo` command.

---

#### **g) `update_dish` Function**

```c
void update_dish() {
    char dish_id[10];
    printf("Enter the Dish ID to update (e.g., 1, 2, 3):\n");
    scanf("%s", dish_id);

    char command[512];
    snprintf(command, sizeof(command), "grep -q '^%s,' %s", dish_id, DISHES_FILE);
    if (system(command) != 0) {
        printf("Error: Dish not found!\n");
        return;
    }

    char new_dish_name[50], new_dish_description[100], new_dish_price[10], new_dish_prep_time[10];
    printf("Enter new Dish Name (or press Enter to keep the current):\n");
    scanf(" %[^\n]s", new_dish_name);
    printf("Enter new Dish Description (or press Enter to keep the current):\n");
    scanf(" %[^\n]s", new_dish_description);
    printf("Enter new Dish Price (or press Enter to keep the current):\n");
    scanf("%s", new_dish_price);
    printf("Enter new Dish Preparation Time (or press Enter to keep the current):\n");
    scanf("%s", new_dish_prep_time);

    snprintf(command, sizeof(command), "sed -i 's/^%s,.*/%s,%s,%s,%s,%s/' %s", dish_id, dish_id, new_dish_name, new_dish_description, new_dish_price, new_dish_prep_time, DISHES_FILE);
    system(command); 
    printf("Dish '%s' updated successfully!\n", dish_id);
}
```

- **Purpose**: Allows the admin to update an existing dish’s details.
- It first checks if the dish exists using `grep`. If it exists, it uses `sed` to update the dish's details in the `dishes.txt` file.

---

#### **h) `delete_dish` Function**

```c
void delete_dish() {
    char dish_id[10];
    printf("Enter the Dish ID to delete (e.g., 1, 2, 3):\n");
    scanf("%s", dish_id);

    char command[512];
    snprintf(command, sizeof(command), "grep -q '^%s,' %s", dish_id, DISHES_FILE);
    if (system(command) != 0) {
        printf("Error: Dish not found!\n");
        return;
    }

    snprintf(command, sizeof(command), "sed -i '/^%s,/d' %s", dish_id, DISHES_FILE);
    system(command);
    printf("Dish '%s' deleted successfully!\n", dish_id);
}
```

- **Purpose**: Allows the admin to delete a dish from the

 menu.
- It first checks if the dish exists using `grep`. If found, it uses `sed` to remove the dish from `dishes.txt`.

---

#### **i) `generate_sales_report` Function**

```c
void generate_sales_report() {
    char command[512];
    snprintf(command, sizeof(command), "awk -F',' '{if ($9 == \"Completed\") total += $8} END {print \"Total Sales: \" total \" tk\"}' %s", ORDERS_FILE);
    system(command);
}
```

- **Purpose**: Generates a sales report by summing the total sales from completed orders.
- It uses `awk` to filter the completed orders and calculates the total sales.

---

### **4. Admin and Customer Menus**

- **Admin Menu**:
  The **Admin Menu** allows the admin to manage dishes and view reports. It provides options to:
  - View all dishes.
  - Add, update, or delete dishes.
  - Generate sales reports.
  
- **Customer Menu**:
  The **Customer Menu** allows customers to view dishes, place orders, cancel orders, and search for dishes.

### **5. Main Function**

The **main function**:
- Asks whether the user is an **admin** or **customer**.
- If admin, it asks for login credentials (username and password).
- Based on the input, it either opens the **Admin Menu** or **Customer Menu**.

---

### **Conclusion**

This program demonstrates basic functionality for managing a restaurant's menu and orders using **C programming** and file manipulation. The admin can manage dishes and view sales reports, while customers can place and manage their orders.

