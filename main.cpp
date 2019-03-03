#include <iostream>
using namespace std;
/*
Po sprawdzeniu ratio sprawdzić czy więcej przedmiotów z niższym nie wejdzie
*/


struct item{
    int weight;
    int value;
    float ratio;
    short int pos;

};

float ratio_counter(int weight, int value){
    float ratio = (float)(value/weight);
    return ratio;
}
/*
void swap_item(item *cmp_1, item *cmp_2)  {
    item swp = *cmp_1;
    *cmp_1 = *cmp_2;
    *cmp_2 = swp;
}
 */
/*
void swap_int (int *cmp_1, int *cmp_2)  {
    int swp = *cmp_1;
    *cmp_1 = *cmp_2;
    *cmp_2 = swp;
}
*/

item* loader(int n){
    item * tab;
    tab = new item[n];
    item swp;

    for (short int i = 0; i <n; i++){
        cin >> tab[i].weight >> tab[i].value;
        tab[i].ratio = ratio_counter(tab[i].weight, tab[i].value);
        tab[i].pos = i + 1;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < (n - 1); j++) {
            if (tab[j].ratio < tab[j + 1].ratio) {
                swp = tab[j];
                tab[j] = tab[j + 1];
                tab[j + 1] = swp;
            }
        }
    }
    return tab;
   // delete [] tab;                  // ups
}




int main() {

    int capacity, n, sum_weight = 0, sum_value = 0;
    short int j = 0, sw = 0;
    item * tab;

    cin >> capacity >> n;

    short int * backpack = new short int[n];
    tab = loader(n);

    while ((sum_weight < capacity) && (n > 0)){
        if ((sum_weight + tab[n].weight) <= capacity){
            sum_weight += tab[n].weight;
            sum_value += tab[n].value;
            backpack[j] = tab[n].pos;
            j++;
        }
        n--;
    }

    delete [] tab;
    for (int i = 0; i < j; i++) {
        for (int k = 0; k < (j - 1); k++) {
            if (backpack[k] > backpack[k + 1]){
                sw = backpack[k];
                backpack[k] = backpack[k + 1];
                backpack[k + 1] = sw;
            }
        }
    }

    cout << sum_value << endl;

    for (int i=0; i < j; i++){
        cout << backpack[i] << " ";
    }
    delete [] backpack;

    return 0;
}