// Name     : Neeraj Mirji
// College  : National Instuitute Of technology Karnataka Surathkal




#include<bits/stdc++.h>
using namespace std;
 
#define SIZE 100000
#define   R   99991


class doubleHash
{
public:
    long int *hashTable;
    int curr_size;

    doubleHash()
    {
        hashTable = new long int[SIZE]; 
        curr_size = 0; 
        for (int i = 0; i < SIZE; i++) 
            hashTable[i] = -1; 
    }

    int hash1(int k)
    {
        return(k%SIZE);
    }

    int hash2(int k)
    {
        return(R - (k%R));
    }

    bool isFull()
    {
        return(curr_size == SIZE);
    }

    void insertHash(int key) 
    { 
        if (isFull()) 
            return; 

        int index = hash1(key); 
        if (hashTable[index] != -1)
         { 
            int index2 = hash2(key); 
            int i = 1; 
            while (1) {  
                       int newIndex = (index + i * index2) % SIZE; 
                       if (hashTable[newIndex] == -1)
                        { 
                        hashTable[newIndex] = key; 
                        break; 
                        } 
                        i++; 
                        } 
        } 
  
        else hashTable[index] = key;
             
        curr_size++; 
    }


    bool search(int key) 
    { 
        int index1 = hash1(key); 
        int index2 = hash2(key); 
        int i = 0; 
        while (hashTable[(index1 + i * index2) % SIZE] != key) 
        { 
            if (hashTable[(index1 + i * index2) % SIZE] == -1) { 
                return false; 
            } 
            i++; 
        } 
        return true;
    } 

    bool deleteKey(int key)
    {
        if(search(key))
        {
         int index1 = hash1(key); 
         int index2 = hash2(key); 
         int i = 0;
         while (hashTable[(index1 + i * index2) % SIZE] != key) 
         { 
            i++; 
         } 
         hashTable[(index1 + i * index2) % SIZE] = -1;
         curr_size--;
         return true;
        }
        else return false;
    }

    void displayHash() 
    { 
        for (int i = 0; i < SIZE; i++) { 
            if (hashTable[i] != -1) 
                cout << i << " --> "
                     << hashTable[i] << endl; 
            else
                cout << i << endl; 
        } 
    } 
};

int main()
{
    doubleHash h;
    float time[200000] = {0};
    int index = 0;
    clock_t start, end;
    double search_time;
    float lamda = 0;
    int n =1;
    int successful_search_count = 0;
     int unsuccessful_search_count = 0;


    while(lamda<=0.8)
    {
       
       int successful_delete_count = 0;
       int unsuccessful_delete_count = 0;
       int insert_count = 0;
        cout<<"initial value of loading factor : "<<lamda<<endl;
        for(int i=0 ; i<4000 ;i++)
    {
        int j = rand() % n*5000;    // generates any no from 0 n*10000
        h.insertHash(j);
        insert_count++;
    }
    cout<<insert_count<<" Numbers SUCCESSFULLY inserted! "<<endl;

    for(int i=0 ; i<2000 ;i++)
    {
        int j = rand() % n*1000;    // generates any no from 0 n*10000
        if(h.deleteKey(j)) successful_delete_count++;
        else unsuccessful_delete_count++;
    }
    cout<<successful_delete_count<<" Numbers SUCCESSFULLY deleted! "<<endl;
    cout<<unsuccessful_delete_count<<" Numbers UNSUCCESSFULLY deleted! "<<endl;
    cout<<"Numbers inserted : "<<h.curr_size<<endl;
    lamda = (float)h.curr_size/(float)SIZE;

    for(int i=0 ; i<7000;i++)
    {
        int j = rand() % n*5000;    // generates any no from 0 to 100000
        start = clock();
        if(h.search(j)) successful_search_count++;
        else unsuccessful_search_count++;
        end = clock();
        search_time = ((double) (end - start)) / CLOCKS_PER_SEC;
        cout<<"element searched : "<<j<<"->"<<"search_time : "<<search_time<<endl;
        index++;
    }
    cout<<successful_search_count+unsuccessful_search_count<<" Numbers searched! "<<endl;
    n++;

    cout<<"final value of loading factor : "<<lamda<<endl<<endl<<endl;
    
    }
    
    cout<<" DONE !"<<endl;
    
    
    
    return 0;


    return 0 ;
}