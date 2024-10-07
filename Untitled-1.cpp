#include <iostream>
#include <string>

using namespace std;

struct Review {
    float rating;
    string comment;
    Review* next;
};

class LinkedList {
public:
    LinkedList() : head(nullptr), tail(nullptr), totalRating(0.0f), reviewCount(0) {}

    void addHead(float rating, const string& comment) {
        Review* newReview = new Review{rating, comment, head};
        head = newReview;
        if (!tail) tail = head;
        totalRating += rating;
        reviewCount++;
    }

    void addTail(float rating, const string& comment) {
        Review* newReview = new Review{rating, comment, nullptr};
        if (tail) {
            tail->next = newReview;
        } else {
            head = newReview;
        }
        tail = newReview;
        totalRating += rating;
        reviewCount++;
    }

    void printReviews() const {
        Review* current = head;
        int index = 1;
        while (current) {
            cout << "> Review #" << index++ << ": " << current->rating << ": " << current->comment << endl;
            current = current->next;
        }
        if (reviewCount > 0) {
            cout << "> Average: " << totalRating / reviewCount << endl;
        }
    }

    ~LinkedList() {
        while (head) {
            Review* temp = head;
            head = head->next;
            delete temp;
        }
    }

private:
    Review* head;
    Review* tail;
    float totalRating;
    int reviewCount;
};

int main() {
    LinkedList reviews;
    int choice;
    cout << "Which linked list method should we use?\n";
    cout << "    [1] New nodes are added at the head of the linked list\n";
    cout << "    [2] New nodes are added at the tail of the linked list\n";
    cout << "Choice: ";
    cin >> choice;
    cin.ignore();

    char another = 'y';
    while (another == 'y' || another == 'Y') {
        float rating;
        string comment;
        cout << "Enter review rating 0-5: ";
        cin >> rating;
        cin.ignore();
        cout << "Enter review comments: ";
        getline(cin, comment);

        if (choice == 1) {
            reviews.addHead(rating, comment);
        } else {
            reviews.addTail(rating, comment);
        }

        cout << "Enter another review? Y/N: ";
        cin >> another;
        cin.ignore();
    }

    cout << "Outputting all reviews:\n";
    reviews.printReviews();

    return 0;
}
