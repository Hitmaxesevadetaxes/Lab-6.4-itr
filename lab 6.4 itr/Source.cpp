    #include <iostream>
    #include <vector>
    #include <algorithm>
    #include <cmath>
    #include <iomanip>
    #include <ctime>
    #include <Windows.h>

    std::vector<double> create_array(int n) {
        std::vector<double> arr(n);
        for (int i = 0; i < n; ++i) {
            arr[i] = (static_cast<double>(rand()) / RAND_MAX) * 200.0 - 100.0;
        }
        return arr;
    }

    void print_array(const std::vector<double>& arr) {
        std::cout << "[";
        for (size_t i = 0; i < arr.size(); ++i) {
            std::cout << std::fixed << std::setprecision(2) << arr[i];
            if (i != arr.size() - 1) {
                std::cout << ", ";
            }
        }
        std::cout << "]" << std::endl;
    }

    double sum_positive_elements(const std::vector<double>& arr) {
        double sum = 0.0;
        for (double x : arr) {
            if (x > 0) {
                sum += x;
            }
        }
        return sum;
    }

    double product_between_max_min(const std::vector<double>& arr) {
        int max_index = 0;
        int min_index = 0;
        for (size_t i = 1; i < arr.size(); ++i) {
            if (std::abs(arr[i]) > std::abs(arr[max_index])) {
                max_index = i;
            }
            if (std::abs(arr[i]) < std::abs(arr[min_index])) {
                min_index = i;
            }
        }

        if (max_index > min_index) {
            std::swap(max_index, min_index);
        }

        double product = 1.0;
        for (int i = min_index + 1; i < max_index; ++i) {
            product *= arr[i];
        }
        return product;
    }

    std::vector<double> sort_odd_elements_desc(const std::vector<double>& arr) {
        std::vector<double> odd_elements;
        for (double x : arr) {
            if (static_cast<int>(x) % 2 != 0) {
                odd_elements.push_back(x);
            }
        }
        std::sort(odd_elements.rbegin(), odd_elements.rend());

        std::vector<double> result;
        size_t odd_index = 0;
        for (double x : arr) {
            if (static_cast<int>(x) % 2 != 0) {
                result.push_back(odd_elements[odd_index++]);
            }
            else {
                result.push_back(x);
            }
        }
        return result;
    }

    int main() {
        SetConsoleCP(1251);
        SetConsoleOutputCP(1251);

        std::srand(static_cast<unsigned int>(std::time(0)));

        int n;
        std::cout << "Введіть кількість елементів масиву: ";
        std::cin >> n;

        std::vector<double> arr = create_array(n);

        std::cout << "Початковий масив:" << std::endl;
        print_array(arr);

        double positive_sum = sum_positive_elements(arr);
        std::cout << "Сума додатних елементів: " << std::fixed << std::setprecision(2) << positive_sum << std::endl;

        double product = product_between_max_min(arr);
        std::cout << "Добуток елементів між максимальним та мінімальним за модулем: " << product << std::endl;

        std::vector<double> sorted_arr = sort_odd_elements_desc(arr);
        std::cout << "Модифікований масив:" << std::endl;
        print_array(sorted_arr);

        return 0;
    }