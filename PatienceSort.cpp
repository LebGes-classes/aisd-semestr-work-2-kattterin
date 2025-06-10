#include "PatienceSort.h"

vector<int> PatienceSort::patienceSort(vector<int>& array)
{
    vector<stack<int>> piles;

    for (int card : array) {
        // Найти подходящую кучку для текущей карты
        auto it = lower_bound(piles.begin(), piles.end(), card, [](const stack<int>& s, int value) {
            return s.top() < value;
            });

        // Если не нашли подходящую кучку, создаем новую
        if (it == piles.end()) {
            stack<int> newPile;
            newPile.push(card);
            piles.push_back(newPile);
        }
        else {
            it->push(card);
        }
    }

    // Сбор всех карт обратно в отсортированный массив
    vector<int> sortedArray;
    while (!piles.empty()) {
        // Найти минимальную верхнюю карту
        int minIndex = 0;
        for (int i = 1; i < piles.size(); ++i) {
            if (piles[i].top() < piles[minIndex].top()) {
                minIndex = i;
            }
        }
        // Добавить минимальную карту в отсортированный массив
        sortedArray.push_back(piles[minIndex].top());
        piles[minIndex].pop();

        // Удалить пустую кучку
        if (piles[minIndex].empty()) {
            piles.erase(piles.begin() + minIndex);
        }
    }

    return sortedArray;
}
