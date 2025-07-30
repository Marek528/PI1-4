#include <iostream>
#include <memory>

void swapByReference(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void swapByPointer(int *a, int *b)
{
    if (!a || !b)
    {
        std::cerr << "chyba: nullptr bol odovzdany do swapByPointer!" << std::endl;
        return;
    }
    int temp = *a;
    *a = *b;
    *b = temp;
}

void swapBySmartPointer(std::unique_ptr<int> &a, std::unique_ptr<int> &b)
{
    a.swap(b);
}

int main()
{
    int x, y;
    std::cout << "zadajte dve cele cisla: ";
    std::cin >> x >> y;

    int x_orig = x, y_orig = y;

    std::cout << "\npred vymenou (referencia): x = " << x << ", y = " << y << std::endl;
    swapByReference(x, y);
    std::cout << "po vymene (referencia): x = " << x << ", y = " << y << "\n";

    int *px = new int(x_orig);
    int *py = new int(y_orig);
    std::cout << "\npred vymenou (pointer): *px = " << *px << ", *py = " << *py << std::endl;
    swapByPointer(px, py);
    std::cout << "po vymene (pointer): *px = " << *px << ", *py = " << *py << "\n";
    delete px;
    delete py;

    auto spx = std::make_unique<int>(x_orig);
    auto spy = std::make_unique<int>(y_orig);
    std::cout << "\npred vymenou (smart pointer): *spx = " << *spx << ", *spy = " << *spy << std::endl;
    swapBySmartPointer(spx, spy);
    std::cout << "po vymene (smart pointer): *spx = " << *spx << ", *spy = " << *spy << "\n";

    return 0;
}