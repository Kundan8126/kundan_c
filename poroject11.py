import os
import datetime

def generate_bills():
    dishes={}
    try:
        with open("all_dish.txt","r") as k:
            for line in k:
                code, name, price = line.strip().split(",")
                dishes[code]= (name,float(price))
    except FileNotFoundError:
        print("Dish file not found")
        return
    total=0
    while True:
        code = input("enter dish code:")
        if code not in dishes:
            print("dish code not found")
        else:
            quantity=int(input("enter quantity :"))
            price = dishes[code][1]
            amount = quantity*price
            total += amount
            print(f"{dishes[code][0]} X {quantity}= Rs{amount:.3f}")
        count=input("add more items? (y/n):")
        if count.lower()!='y':
            break
        now = datetime.datetime.now()
        bill_number= next_bill_number()
        with open ("all_bills.text","a") as k:
            k.write(f"{bill_number},{now.strftime('%Y-%m-%d')},{total}\n")
        print(f"\nTotal Bill: Rs.{total:.3f}")
        print("bill generated adn saved successfully")


def next_bill_number():
        try:
            with open("all_bills.txt", "r") as k:
                lines = k.readlines()
                if not lines:
                    return 1
                last_line = lines[-1]
                return int(last_line.split(",")[0]) + 1
        except FileNotFoundError:
            return 1
        
def view_all_dish():
        try:
            with open("all_dish.txt", "r") as k:
                for line in k:
                    code, name, price = line.strip().split(",")
                    print(f"Code: {code} | Name: {name} | Price: Rs{price}")
        except FileNotFoundError:
            print("No dishes found.")


def add_new_dish():
        code = input("Enter Dish Code: ")
        name = input("Enter Dish Name: ")
        price = input("Enter Dish Price: ")
        with open("all_dish.txt", "a") as k:
         k.write(f"{code},{name},{price}\n")
        print("Dish added successfully.")
    
def update_dish_price():
    code_to_update = input("Enter Dish Code to Update: ")
    updated = False
    try:
        with open("all_dish.txt", "r") as k:
            dishes = k.readlines()
        with open("all_dish.txt", "w") as k:
            for line in dishes:
                code, name, price = line.strip().split(",")
                if code == code_to_update:
                    new_price = input(f"Enter new price for {name}: ")
                    k.write(f"{code},{name},{new_price}\n")
                    updated = True
                else:
                    k.write(line)
        if updated:
            print("Price updated successfully.")
        else:
            print("Dish code not found.")
    except FileNotFoundError:
        print("Dish file not found.")

def add_new_employee():
    name = input("Enter Employee Name: ")
    contact = input("Enter Contact No.: ")
    email = input("Enter Email: ")
    with open("all_employees.txt", "a") as f:
        f.write(f"{name},{contact},{email}\n")
    print("Employee added successfully.")

def check_today_income():
    today = datetime.datetime.now().strftime("%Y-%m-%d")
    check_income_on_date(today)

def check_income_on_date():
    date = input("Enter date (YYYY-MM-DD): ")
    check_income_on_date(date)


def check_income_on_date(date):
    total = 0
    try:
        with open("all_bills.txt", "r") as k:
            for line in k:
                bill_no, bill_date, bill_amt = line.strip().split(",")
                if bill_date == date:
                    total += float(bill_amt)
        print(f"Total income on {date}: ₹{total:.2f}")
    except FileNotFoundError:
        print("No bills found.")


def check_income_between_dates():
    start_date = input("Enter Start Date (YYYY-MM-DD): ")
    end_date = input("Enter End Date (YYYY-MM-DD): ")
    total = 0
    try:
        with open("all_bills.txt", "r") as k:
            for line in k:
                bill_no, bill_date, bill_amt = line.strip().split(",")
                if start_date <= bill_date <= end_date:
                    total += float(bill_amt)
        print(f"Total income between {start_date} and {end_date}: Rs{total:.3f}")
    except FileNotFoundError:
        print("No bills found.")

def take_backup():
    try:
        import shutil
        files = ["all_bills.txt", "all_dish.txt", "all_employees.txt"]
        for file in files:
            if os.path.exists(file):
                shutil.copy(file, f"backup_{file}")
        print("Backup created successfully.")
    except Exception as e:
        print("Backup failed:", e)

def send_reminder():
    try:
        with open("library_records.txt", "r") as f:
            for line in f:
                name, contact, return_date = line.strip().split(",")
                return_dt = datetime.datetime.strptime(return_date, "%Y-%m-%d")
                if return_dt.date() == datetime.datetime.now().date() + datetime.timedelta(days=1):
                    print(f"Reminder to {name}: 'You have a book to return Tomorrow'")
    except FileNotFoundError:
        print("No library records found.")

while True:
    print("\n--- Restaurant Billing Application ---")
    print("1. Generate Bill")
    print("2. View All Dish")
    print("3. Add New Dish")
    print("4. Update Dish Price")
    print("5. Add New Employee")
    print("6. Check Today's Total Income")
    print("7. Check Total Income on specific Date")
    print("8. Check Total Income between Dates")
    print("11. Take Backup")
    print("12. Send Reminder")
    print("0. Exit")

    choice = input("Enter your choice: ")

    if choice == "1":
        generate_bills()
    elif choice == "2":
        view_all_dish()
    elif choice == "3":
        add_new_dish()
    elif choice == "4":
        update_dish_price()
    elif choice == "5":
        add_new_employee()
    elif choice == "6":
        check_today_income()
    elif choice == "7":
        check_income_on_date()
    elif choice == "8":
        check_income_between_dates()
    elif choice == "11":
        take_backup()
    elif choice == "12":
        send_reminder()
    elif choice == "0":
        print("Exiting...")
        break
    else:
        print("Invalid choice. Please try again.")


    




