//#include <iostream>
//#include <cstdlib>
//
//using namespace std;
//
//void display(int* set, int n)
//{
//    cout << "\nArray: ";
//    for (int i = 0; i < n; i++)
//    {
//        cout << set[n] << " ";
//    }
//    cout << endl;
//}
//
//int main()
//{
//
//    int* Set = NULL;
//    int element;
//    char Choice;
//    int n = 0;
//
//    do
//    {
//        cout << "  Size of the array : " << sizeof(Set) / sizeof(int) << endl;
//        cout << "  Enter an element : ";
//        cin >> element;
//
//        n++;
//        Set = (int*)realloc(Set, n * sizeof(int));
//        Set[n - 1] = element;
//
//        display(Set, n);
//
//        cout << "  Do you want to enter another element? (y/n) : ";
//        cin >> Choice;
//    } while (Choice == 'y' || Choice == 'Y');
//
//    cout << "  Size of the array : " << sizeof(Set) / sizeof(int) << endl;
//    return 0;
//}