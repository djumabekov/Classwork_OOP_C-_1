#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
using namespace std;
#define RAND(Min,Max) (rand()%((Max)-(Min)+1)+(Min))
struct LC { LC() { system("chcp 1251 > nul"); srand(time(0)); }~LC() { cin.get(); cin.get(); } }_;

/*
Создайте класс Queue обычной очереди для работы
с целыми значениями.
Требуется создать реализации для типичных
операций над элементами:
 * IsEmpty - проверка очереди на пустоту
 * IsFull - проверка очереди на заполнение
 * Enqueue - добавление элемента в очередь
 * Dequeue - удаление элемента из очереди
 * Show - отображение всех элементов очереди на экран
*/

// Шаблон класса простой очереди

template<typename T>
class Queue
{
private:
    T* Wait; // Массив элементов очереди
    size_t MaxSize; // Максимальный размер очереди    
    size_t Size; //Текущий размер очереди    
public:
    Queue() :Wait(), MaxSize(), Size() {};
    Queue(size_t maxSize) :Queue() { SetMaxSize(maxSize); };  // конструктор с указанием максимального размера очереди
    // конструктор иниц-ции массивом
    Queue(T* mas, size_t size) :Queue(size + 10)
    { // Queue (size)
        for (size_t i = 0; i < size; i++) {
            Enqueue(mas[i]);
            // this->Wait[i] = mas[i];
        }
    }
    Queue(const Queue& obj) :Queue() { *this = obj; }
    Queue& operator=(const Queue& obj)
    {
        if (this != &obj) {
            SetMaxSize(obj.GetMaxSize());
            for (size_t i = 0; i < obj.GetSize(); i++) {
                this->Wait[i] = obj.Wait[i];
            }
            this->Size = obj.Size;
        }
        return *this;
    }
    ~Queue() { delete[]Wait; };

    // Добавить элемент в конец очереди
    void Enqueue(const T& val)
    {
        if (!(Size < MaxSize)) { SetMaxSize(Size + 10); }
        //if (Size >= MaxSize) { SetMaxSize(Size * 1.5 + 1); }
        Wait[Size++] = val;
        //Wait[Size] = val; Size++;
    }

    // Извлечь элемент из начала очереди с возможностью его удаления из очереди
    T Dequeue(bool Delete = true)
    {
        if (Delete == false) { return GetFirst(); } // return Wait[0];
        T temp = GetFirst();
        for (size_t i = 0; i < Size - 1; i++) {
            // [i]= [i + 1];
            Wait[i] = Wait[i + 1];
        }
        Size--;
        return temp;
    }

    // Очистить очередь
    void Clear() { Size = 0; }

    // Проверка - очередь пустая?
    bool IsEmpty() const {
        if (GetSize() == 0) { return true; }
        return false;
    }

    // Проверка на переполнение очереди - Очередь заполнена?
    bool IsFull() const {
        if (GetSize() == GetMaxSize()) { return true; }
        return false;
    }

    void SetMaxSize(size_t newmaxsize)
    {
        if (newmaxsize > 0)
        {
            T* temp = new T[newmaxsize];
            size_t minsize = (Size < newmaxsize) ? Size : newmaxsize;
            for (size_t i = 0; i < minsize; i++)
            {// for (size_t i = 0; i < Size; i++) without minsize
                temp[i] = Wait[i];
            }
            if (Size > newmaxsize) { Size = newmaxsize; }
            delete[]Wait;
            Wait = temp;
            MaxSize = newmaxsize;
        }
        else { cout << "Error : newMaxSize < 0!\n"; }
    }

    // получить первый элемент очереди без его удаления
    T& GetFirst() const
    {
        if (!IsEmpty()) { return Wait[0]; }
        throw  "Error Queue is empty!";
    }

    // Получить текущий размер очереди
    size_t GetSize() const { return Size; }

    // Получить максимальный размер очереди
    size_t GetMaxSize() const { return MaxSize; };

    template<class T1>
    friend ostream& operator<<(ostream& os, const Queue<T1>& obj)
    {
        os << "MaxSize = " << obj.GetMaxSize() << endl;
        os << "Size = " << obj.GetSize() << endl;
        for (size_t i = 0; i < obj.GetSize(); i++) {
            os << obj.Wait[i] << endl;
        }
        return os;
    }
}; // class Queue<T>;


int main()
{
    int size;
    cout << "Введите размер очереди: ";
    cin >> size;
    Queue<string> que(size);

    // Постановка элементов в очередь
    que.Enqueue("Первая строка");
    que.Enqueue("Строка 2");
    que.Enqueue("Строка 3");

    cout << "Queue: " << que << endl;

    // Обработка очереди - извлечение элементов из очереди
    while (!que.IsEmpty()) {
        cout << que.Dequeue() << endl;
    }

    cout << "Queue: " << que << endl;
}


