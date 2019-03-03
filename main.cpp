#include <iostream>
using namespace std;
/*
Po sprawdzeniu ratio sprawdzić czy więcej przedmiotów z niższym nie wejdzie
*/


struct item{
    int weight;
    int value;
    float ratio;
    int pos;

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

    for (int i = 0; i <n; i++){
        cin >> tab[i].weight >> tab[i].value;
        tab[i].ratio = ratio_counter(tab[i].weight, tab[i].value);
        tab[i].pos = i + 1;
    }

    return tab;
   // delete [] tab;                  // ups
}




int main() {

    int capacity, n, m, sum_weight_1 = 0, sum_value_1 = 0, sum_weight_2 = 0, sum_value_2 = 0, sum_weight_3 = 0, sum_value_3 = 0, sum_weight_4 = 0, sum_value_4 = 0;
    int j = 0, l = 0, r = 0, s, a, b = 0;


    cin >> capacity >> n;
    m = n;
    s = n;
    a = n;
    int * backpack_1 = new int[n];
    int * backpack_2 = new int[n];
    int * backpack_3 = new int[n];
    int * backpack_4 = new int[n];
    item * tab_1;
    item * tab_2;
    item * tab_3;


    tab_1 = loader(n);
    tab_2 = tab_1;
    tab_3 = tab_1;


    for (int i = 0; i < n; i++) {
        for (int p = 0; p < (n - 1); p++) {
            if (tab_1[p].ratio > tab_1[p + 1].ratio) {
                item swp = tab_1[p];
                tab_1[p] = tab_1[p + 1];
                tab_1[p + 1] = swp;
            }
        }
    }
    while ((sum_weight_1 <= capacity) && (n > 0)){
        if ((sum_weight_1 + tab_1[n].weight) <= capacity){
            sum_weight_1 += tab_1[n].weight;
            sum_value_1 += tab_1[n].value;
            backpack_1[j] = tab_1[n].pos;
            j++;
        }
        n--;
    }

    for (int i = 0; i < j; i++) {
        for (int k = 0; k < (j - 1); k++) {
            if (backpack_1[k] > backpack_1[k + 1]){
                int sw = backpack_1[k];
                backpack_1[k] = backpack_1[k + 1];
                backpack_1[k + 1] = sw;
            }
        }
    }





    for (int i = 0; i < m; i++) {
        for (int o = 0; o < (m - 1); o++) {
            if (tab_2[o].value > tab_2[o + 1].value) {
                item swp = tab_2[o];
                tab_2[o] = tab_2[o + 1];
                tab_2[o + 1] = swp;
            }
        }
    }

    while (sum_weight_2 <= capacity && m > 0){
        if ((sum_weight_2 + tab_2[m].weight) <= capacity){
            sum_weight_2 += tab_2[m].weight;
            sum_value_2 += tab_2[m].value;
            backpack_2[l] = tab_2[m].pos;
            l++;
        }
        m--;
    }

    for (int i = 0; i < l; i++) {
        for (int k = 0; k < (l - 1); k++) {
            if (backpack_2[k] > backpack_2[k + 1]){
                int sw = backpack_2[k];
                backpack_2[k] = backpack_2[k + 1];
                backpack_2[k + 1] = sw;
            }
        }
    }




    for (int i = 0; i < s; i++) {
        for (int o = 0; o < (s - 1); o++) {
            if (tab_3[o].weight > tab_3[o + 1].weight) {
                item swp = tab_3[o];
                tab_3[o] = tab_3[o + 1];
                tab_3[o + 1] = swp;
            }
        }
    }

    while ((sum_weight_3 <= capacity) && (s > 0)){
        if ((sum_weight_3 + tab_3[s].weight) <= capacity){
            sum_weight_3 += tab_3[s].weight;
            sum_value_3 += tab_3[s].value;
            backpack_3[r] = tab_3[s].pos;
            r++;
        }
        s--;
    }

    for (int i = 0; i < r; i++) {
        for (int k = 0; k < (r - 1); k++) {
            if (backpack_3[k] > backpack_3[k + 1]){
                int sw = backpack_3[k];
                backpack_3[k] = backpack_3[k + 1];
                backpack_3[k + 1] = sw;
            }
        }
    }



    int c = 0;

    while ((sum_weight_4 <= capacity) && (c < a)){
        if ((sum_weight_4 + tab_1[c].weight) <= capacity){
            sum_weight_4 += tab_1[c].weight;
            sum_value_4 += tab_1[c].value;
            backpack_4[b] = tab_1[c].pos;
            b++;
        }
        c++;
    }

    for (int i = 0; i < b; i++) {
        for (int k = 0; k < (b - 1); k++) {
            if (backpack_4[k] > backpack_4[k + 1]){
                int sw = backpack_4[k];
                backpack_4[k] = backpack_4[k + 1];
                backpack_4[k + 1] = sw;
            }
        }
    }




    if (sum_value_1 >= sum_value_2 && sum_value_1 >= sum_value_3 && sum_value_1 >= sum_value_4) {
            cout << sum_value_1 << endl;

            for (int i = 0; i < j; i++) {
                cout << backpack_1[i] << " ";
            }
        }
    else {

        if (sum_value_2 >= sum_value_1 && sum_value_2 >= sum_value_3 && sum_value_2 >= sum_value_4) {
            cout << sum_value_2 << endl;

            for (int i = 0; i < l; i++) {
                cout << backpack_2[i] << " ";
            }
        }
        else{

             if (sum_value_3 >= sum_value_1 && sum_value_3 >= sum_value_2 && sum_value_3 >= sum_value_4) {

                cout << sum_value_3 << endl;

                for (int i = 0; i < r; i++) {
                    cout << backpack_3[i] << " ";
                }
            }
             else{
                 if (sum_value_4 >= sum_value_1 && sum_value_4 >= sum_value_2 && sum_value_4 >= sum_value_3){
                     cout << sum_value_4 << endl;

                     for (int i = 0; i < c; i++) {
                         cout << backpack_4[i] << " ";
                     }
                 }
             }

        }
    }



        delete [] tab_1;

        delete [] backpack_1;
        delete [] backpack_2;
        delete [] backpack_3;
        delete [] backpack_4;

    return 0;
}