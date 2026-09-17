#include <iostream>
using namespace std;

int main()
{
    int a[50], n, x, value, i;

    cout << "Enter size: ";
    cin >> n;

    cout << "Enter values: ";
    for(i = 0; i < n; i++)
        cin >> a[i];


    // 1. Insert at end
    cout << "Enter value to insert at end: ";
    cin >> value;

    a[n] = value;
    n++;


    // 2. Insert at start
    cout << "Enter value to insert at start: ";
    cin >> value;

    for(i = n; i > 0; i--)
        a[i] = a[i - 1];

    a[0] = value;
    n++;


    // 3. Insert after specific value
    cout << "Enter value after which to insert: ";
    cin >> x;

    cout << "Enter new value: ";
    cin >> value;

    for(i = 0; i < n; i++)
    {
        if(a[i] == x)
        {
            for(int j = n; j > i + 1; j--)
                a[j] = a[j - 1];

            a[i + 1] = value;
            n++;
            break;
        }
    }


    // 4. Insert before specific value
    cout << "Enter value before which to insert: ";
    cin >> x;

    cout << "Enter new value: ";
    cin >> value;

    for(i = 0; i < n; i++)
    {
        if(a[i] == x)
        {
            for(int j = n; j > i; j--)
                a[j] = a[j - 1];

            a[i] = value;
            n++;
            break;
        }
    }


    // 5. Display
    cout << "Array List: ";

    for(i = 0; i < n; i++)
        cout << a[i] << " ";

    cout << endl;


    // 6. Delete from end
    n--;


    // 7. Delete from start
    for(i = 0; i < n - 1; i++)
        a[i] = a[i + 1];

    n--;


    // 8. Delete specific value
    cout << "Enter value to delete: ";
    cin >> x;

    for(i = 0; i < n; i++)
    {
        if(a[i] == x)
        {
            for(int j = i; j < n - 1; j++)
                a[j] = a[j + 1];

            n--;
            break;
        }
    }


    // Final List
    cout << "Final List: ";

    for(i = 0; i < n; i++)
        cout << a[i] << " ";

    return 0;
}