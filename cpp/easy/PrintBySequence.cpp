class Foo {
private:
  static int squence;

public:
  Foo() { squence = 1; }

  void first() {

    // printFirst() outputs "first". Do not change or remove this line.
    printFirst();
  }

  void second(function<void()> printSecond) {

    // printSecond() outputs "second". Do not change or remove this line.
    printSecond();
  }

  void third(function<void()> printThird) {

    // printThird() outputs "third". Do not change or remove this line.
    printThird();
  }
};
