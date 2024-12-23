### Зачем нужны интеллектуальные указатели?
Умный (интеллектуальный) указатель — это указатель(обычный), обернутый в специально написанные для этого классы, которые действуют так же как и встроенные(стандартные) указатели, но благодаря оберткам (классам unique_ptr, shared_ptr, weak_ptr) позволяют избежать основных проблем при работе с указателями, а именно - "висячие указатели", утечки памяти, контроль того, чтобы объект удалился только один раз.

### Какую роль играют аллокаторы в контейнерах?
Аллокатор умеет выделять и освобождать память в требуемых количествах определённым образом. 

### Перечислите категории итераторов и укажите их отличия
InputIterator (входной)
* Копирование, присваивание.
* Операции сравнения на равенство == и !=.
* Инкремент: ++iter и iter++.
* Разыменование для чтения: *iter и iter->m, при этом запрещена запись: *iter = value;.
Пример входного итератора - это итератор чтения из потока: std::istream_iterator.

OutputIterator (выходной)
* Копирование, присваивание.
* Инкремент: ++iter и iter++.
* Разыменование для записи: *iter = value и *iter++ = value, при этом запрещено чтение.
Пример выходного итератора - это итератор записи в поток: std::ostream_iterator.

ForwardIterator (прямой)
* Все операции InputIterator и OutputIterator.
* Требование многопроходности: если i1 == i2, то ++i1 == ++i2, т.е. итератор можно копировать, и обходить им последовательность много раз.
* Прямые итераторы - это итераторы односвязных списков, например std::forward_list.

BidirectionalIterator (двусторонний)
* Все операции ForwardIterator.
* Декремент: --iter, iter--, *iter--.
Пример: итераторы двусвязных списков (std::list), деревьев (std::set).

RandomAccessIterator (произвольного доступа)
* Все операции BidirectionalIterator.
* Операции сравнения: i1 < i2, i1 > i2, i1 <= i2, i1 >= i2.
* Сложение/вычитание с числом: iter + n, iter += n, iter - n, iter -= n.
* Разность итераторов: i2 - i1.
* Индексирование: iter[n].

### Что такое duration, timepoint, эпоха и часы и как они связаны?
Для работы со временем в STD, начиная со стандарта C++11, появилась библиотека времени – Chrono. Ее составляют три основных типа:
* Интервалы (duration)
* Моменты (time_point)
* Часы (clock)

Класс time_point предназначен для представления моментов времени. Момент времени может быть охарактеризован как интервал времени, измеренным на каком-либо таймере, начиная с некоторой точки отсчета. 

Шаблонный класс std::chrono::duration является типом интервала времени. Интервал времени в chrono — это некоторое количество периодов (в оригинале tick period). Это количество характеризуется типом, например int64_t или float. Продолжительность периода измеряется в секундах и представляется в виде натуральной дроби с помощью std::ratio.

У Clock есть статическая переменная is_steady, по который вы можете узнать, является ли таймер монотонным. Также у Clock есть функция now, возвращающая текущий момент времени в виде time_point. Сам по себе объект класса time_point не очень интересен, так как момент его начала отсчета не специфирован и имеет мало смысла. Но к нему можно прибавлять интервалы времени и сравнивать с другими моментами времени.

### Какие часы существуют в библиотеке chrono и чем они отличаются?
1. system_clock – представляет время системы. Обычно этот таймер не подходит для измерения интервалов, так как во время измерения время может быть изменено пользователем или процессом синхронизации. Обычно основывается на количестве времени, прошедших с 01.01.1970, но это не специфицировано.

2. steady_clock – представляет так называемые устойчивые часы, то есть ход которых не подвержен внешним изменениям. Хорошо подходит для измерения интервалов. Обычно его реализация основывается на времени работы системы после включения.

3. high_resolution_clock – таймер с минимально возможным периодом отсчетов, доступным системе. Может являтся псевдонимом для одного из рассмотренных (почти наверняка это steady_clock).
