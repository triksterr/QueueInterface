В C++ можно ограничить типы, которые можно использовать в шаблоне, только числовыми или только целочисленными типами, с помощью статических утверждений (`static_assert`) и type traits из стандартной библиотеки. Вот как это можно сделать:

### 1. Ограничение на числовые типы (целые и вещественные)
Для ограничения типов только числовыми (целыми и вещественными) можно использовать `std::is_arithmetic` из библиотеки `<type_traits>`. Этот трейт проверяет, является ли тип арифметическим (целым или вещественным).

```cpp
#include <type_traits>

template <typename T>
class MyClass {
    static_assert(std::is_arithmetic<T>::value, "Тип должен быть числовым (целым или вещественным)");

    // Ваш код класса
};

template <typename T>
void myFunction(T value) {
    static_assert(std::is_arithmetic<T>::value, "Тип должен быть числовым (целым или вещественным)");

    // Ваш код функции
}
```

### 2. Ограничение на целочисленные типы
Для ограничения типов только целочисленными можно использовать `std::is_integral`.

```cpp
#include <type_traits>

template <typename T>
class MyClass {
    static_assert(std::is_integral<T>::value, "Тип должен быть целочисленным");

    // Ваш код класса
};

template <typename T>
void myFunction(T value) {
    static_assert(std::is_integral<T>::value, "Тип должен быть целочисленным");

    // Ваш код функции
}
```

### 3. Ограничение на конкретные типы
Если нужно ограничить типы конкретным набором (например, только `int`, `double`, `float`), можно использовать `std::is_same` в комбинации с логическими операторами:

```cpp
#include <type_traits>

template <typename T>
class MyClass {
    static_assert(
        std::is_same<T, int>::value ||
        std::is_same<T, double>::value ||
        std::is_same<T, float>::value,
        "Тип должен быть int, double или float"
    );

    // Ваш код класса
};

template <typename T>
void myFunction(T value) {
    static_assert(
        std::is_same<T, int>::value ||
        std::is_same<T, double>::value ||
        std::is_same<T, float>::value,
        "Тип должен быть int, double или float"
    );

    // Ваш код функции
}
```

### 4. Использование концептов (C++20)
В C++20 появились концепты, которые упрощают ограничение типов. Например:

```cpp
#include <concepts>

template <std::integral T>
class MyClass {
    // Ваш код класса
};

template <std::integral T>
void myFunction(T value) {
    // Ваш код функции
}
```

Или для числовых типов:

```cpp
#include <concepts>

template <std::arithmetic T>
class MyClass {
    // Ваш код класса
};

template <std::arithmetic T>
void myFunction(T value) {
    // Ваш код функции
}
```

### Итог
- Для ограничения числовыми типами используйте `std::is_arithmetic`.
- Для ограничения целочисленными типами используйте `std::is_integral`.
- В C++20 используйте концепты `std::integral` или `std::arithmetic` для более читаемого кода.

---

Для ограничения шаблонных функций или классов только **беззнаковыми целочисленными типами** в C++ можно использовать type traits из стандартной библиотеки, такие как `std::is_unsigned`. Этот трейт проверяет, является ли тип беззнаковым (например, `unsigned int`, `unsigned long`, `unsigned char` и т.д.).

### Пример с `static_assert` (C++11 и выше)
```cpp
#include <type_traits>

template <typename T>
class MyClass {
    static_assert(std::is_unsigned<T>::value, "Тип должен быть беззнаковым целочисленным");

    // Ваш код класса
};

template <typename T>
void myFunction(T value) {
    static_assert(std::is_unsigned<T>::value, "Тип должен быть беззнаковым целочисленным");

    // Ваш код функции
}
```

### Пример с концептами (C++20)
В C++20 можно использовать концепты для более выразительного синтаксиса. Для ограничения беззнаковыми типами можно создать собственный концепт или использовать комбинацию стандартных концептов.

```cpp
#include <concepts>

template <typename T>
concept UnsignedIntegral = std::unsigned_integral<T>;

template <UnsignedIntegral T>
class MyClass {
    // Ваш код класса
};

template <UnsignedIntegral T>
void myFunction(T value) {
    // Ваш код функции
}
```

Здесь `std::unsigned_integral` — это стандартный концепт, который проверяет, является ли тип беззнаковым целочисленным.

### Пример с ограничением на конкретные беззнаковые типы
Если нужно ограничить типы конкретным набором беззнаковых типов (например, только `unsigned int`, `unsigned long`), можно использовать `std::is_same` в комбинации с логическими операторами:

```cpp
#include <type_traits>

template <typename T>
class MyClass {
    static_assert(
        std::is_same<T, unsigned int>::value ||
        std::is_same<T, unsigned long>::value,
        "Тип должен быть unsigned int или unsigned long"
    );

    // Ваш код класса
};

template <typename T>
void myFunction(T value) {
    static_assert(
        std::is_same<T, unsigned int>::value ||
        std::is_same<T, unsigned long>::value,
        "Тип должен быть unsigned int или unsigned long"
    );

    // Ваш код функции
}
```

### Итог
- Для ограничения беззнаковыми целочисленными типами используйте `std::is_unsigned` (C++11 и выше).
- В C++20 используйте концепт `std::unsigned_integral` для более читаемого и выразительного кода.
- Если нужно ограничить конкретными беззнаковыми типами, используйте `std::is_same` в комбинации с логическими операторами.