#include <iostream>
#include <vector>
#include <stdexcept> 

class Stack {
private:
  std::vector<std::string> items;

public:
  void push(const std::string& item) {
    items.push_back(item);
    std::cout << "Item '" << item << "' pushed to the stack." << '\n';
  }

  std::string pop() {
    if (items.empty()) {
      throw std::runtime_error("Stack is empty. Cannot pop.");
    }
    std::string poppedItem = items.back();
    items.pop_back();
    return poppedItem;
  }

  std::string peek() const {
    if (items.empty()) {
      throw std::runtime_error("Stack is empty. Cannot peek.");
    }
    return items.back();
  }

  void viewStack() const {
    if (items.empty()) {
      std::cout << "Stack is empty.\n";
      std::cout << "|___| top\n";
    }
    else {
      std::cout << "Stack contents (top to bottom):\n";
      std::cout << "|___| \n"; // Top stack marker
      for (int i = items.size() - 1; i >= 0; --i) {
        if (i == items.size() - 1) {
          std::cout << "|_" << items[i] << "_| <-- top\n";
        }
        else {
          std::cout << "|_" << items[i] << "_|\n";
        }
      }
    }
  }

  size_t getSize() const {
    return items.size();
  }

  bool isEmpty() const {
    return items.empty();
  }
};

int main() {
  Stack stack;
  while (true) {
    std::cout << "\nMenu:\n";
    std::cout << "1. Push\n";
    std::cout << "2. Pop\n";
    std::cout << "3. Peek\n";
    std::cout << "4. View Stack\n";
    std::cout << "5. Number of elements in the stack\n";
    std::cout << "6. Exit\n";
    std::cout << "Enter your choice: ";

    int choice;
    std::cin >> choice;

    switch (choice) {
    case 1: {
      std::string item;
      std::cout << "Enter the item to push: ";
      std::cin >> item;
      stack.push(item);
      break;
    }
    case 2: {
      try {
        std::string poppedItem = stack.pop();
        std::cout << "Popped item: " << poppedItem << '\n';
      }
      catch (const std::exception& e) {
        std::cerr << e.what() << '\n';
      }
      break;
    }
    case 3: {
      try {
        std::cout << "Top of the stack: " << stack.peek() << '\n';
      }
      catch (const std::exception& e) {
        std::cerr << e.what() << '\n';
      }
      break;
    }
    case 4:
      stack.viewStack();
      break;
    case 5:
      std::cout << "Number of elements in the stack: " << stack.getSize() << '\n';
      break;
    case 6:
      std::cout << "Exiting program.\n";
      return 0;
    default:
      std::cout << "Invalid choice. Please try again.\n";
      break;
    }
  }
  return 0;
}
