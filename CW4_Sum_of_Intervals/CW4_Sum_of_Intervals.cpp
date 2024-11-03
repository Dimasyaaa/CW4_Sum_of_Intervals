#include <vector> // для векторов
#include <utility> // для работы с парами (pair)
#include <algorithm> // для алгоритмы(swap())

using namespace std; // ну эт вы сами знаете)

// функция сортировки пузырьком, которая принимает вектор пар, это тип интервалы
void bubble_sort(vector<pair<int, int>>& intervals) { 
    bool swapped; // Переменная, произошел ли обмен
    for (size_t i = 0; i < intervals.size(); i++) { // Перебор всех элементов
        swapped = false; // Инициализация переменной обмена в ложное значение на каждой итерации
        for (size_t j = 0; j < intervals.size() - i - 1; j++) { 
            //  цикл для сравнения интервалов
            if (intervals[j].first > intervals[j + 1].first) { 
                // Если начальная точка текущего интервала больше, чем у следующего
                swap(intervals[j], intervals[j + 1]); // меняем их местами
                swapped = true;
            }
        }
        if (!swapped) { // если не было обменов убегаем из цикла)
            break; // 
        }
    }
}

// Функция для суммирования длины объединенных интервалов
int sum_intervals(vector<pair<int, int>> intervals) { 
    if (intervals.empty()) return 0; // Если список пуст, возвращаем 0

    bubble_sort(intervals); // Сортируем интервалы по начальной точке

    vector<pair<int, int>> mergedIntervals; // Вектор для хранения объединенных интервалов

    mergedIntervals.push_back(intervals[0]); // Добавляем первый интервал в массив объединенных интервалов

    for (size_t i = 1; i < intervals.size(); i++) { 
        // Начинаем с второго интервала и проходим все интервалы
        // Проверяем, пересекается ли текущий интервал с последним объединенным интервалом
        if (intervals[i].first <= mergedIntervals.back().second) { 
            // Если начало текущего интервала меньше или равно концу последнего объединенного интервала
            mergedIntervals.back().second = max(mergedIntervals.back().second, intervals[i].second); 
            // Объединяем интервалы, устанавливая конец на максимальное значение
        }
        else { 
            // если интервалчики не пересекаются
            mergedIntervals.push_back(intervals[i]); // добавляем текущий интервал в наш список
        }
 }
// Подсчет общей длины объединенных интервалов
    int total_length = 0; //  общая длинна
    for (const auto& interval : mergedIntervals) { 
        // перебираем все интервалы
        total_length += interval.second - interval.first; // вычисляем длину и добавляем к общей длине
    }
    return total_length; // возвращае длину
}
