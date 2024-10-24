#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

void bubble_sort(vector<pair<int, int>>& intervals) {
    bool swapped;
    for (size_t i = 0; i < intervals.size(); i++) {
        swapped = false; // Инициализация переменной ей на каждой итерации
        for (size_t j = 0; j < intervals.size() - i - 1; j++) {
            if (intervals[j].first > intervals[j + 1].first) {
                swap(intervals[j], intervals[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) {
            break; // Если не было обменов, массив отсортирован
        }
    }
}

int sum_intervals(vector<pair<int, int>> intervals) {
    if (intervals.empty()) return 0; // Если список интервалов пуст, возвращаем 0

    bubble_sort(intervals);

    vector<pair<int, int>> mergedIntervals; // Вектор для объединенных интервалов

    mergedIntervals.push_back(intervals[0]); // Добавляем первый интервал

    for (size_t i = 1; i < intervals.size(); i++) {
        // Если текущий интервал перекрывается с последним объединенным интервалом
        if (intervals[i].first <= mergedIntervals.back().second) {
            // Объединяем интервалы
            mergedIntervals.back().second = max(mergedIntervals.back().second, intervals[i].second);
        }
        else {
            // Иначе, добавляем новый интервал в список
            mergedIntervals.push_back(intervals[i]);
        }
    }

    int totalSum = 0;
    // Суммируем длины объединенных интервалов
    for (const auto& interval : mergedIntervals) {
        totalSum += (interval.second - interval.first);
    }
    return totalSum;
}