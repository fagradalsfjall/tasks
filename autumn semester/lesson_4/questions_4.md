### 1. Какими способами можно задать значения для данных-членов структуры?

Инициализация полей структуры может осуществляться двумя способами:

* присвоение значений элементам структуры в процессе объявления переменной, относящейся к типу структуры;
* с помощью списка инициализаторов (он позволяет инициализировать некоторые или все члены структуры во время объявления переменной типа struct);
* присвоение начальных значений элементам структуры с использованием функций ввода-вывода (например, printf() и scanf()).

### 2. Для чего предназначены списки инициализации в конструкторах структур?

Списки инициализации предназначены для присваивания значений членам структуры. 

### 3. Как конструктор и деструктор структуры могут реализовывать идиому RAII?

Идиома RAII (Resource Acquisition Is Initialization) заключается в том, что некоторый ресурс захватывается в конструкторе объекта, и освобождается в его деструкторе. А поскольку деструктор локальных объектов вызывается автоматически при выходе из метода (или просто из области видимости) не зависимо от причины (нормальное завершение метода или при генерации исключения), то использование этой идиомы является самым простым и эффективным способом написания сопровождаемого C++ кода, безопасного с точки зрения исключений.

### 4. Как стоит рассматривать использование битовых полей и объединений?

**Битовые поля** используются для хранения данных целых типов. При использовании битовых полей в размере типа для них выделяется строго определенное количество бит.

Объявление битового поля в структуре выглядит следующим образом

`unsigned int field : value;`.

**Объединение** – это группирование переменных, которые разделяют одну и ту же область памяти. В зависимости от интерпретации осуществляется обращение к той или другой переменной объединения. Все переменные, что включены в объединение начинаются с одной границы.

Объединение позволяет представить в компактном виде данные, которые могут изменяться. Одни и те же данные могут быть представлены разными способами с помощью объединений.

Объявление объединения (типа объединения или шаблона объединения) начинается с ключевого слова `union`.

### 5. Какими особенностями обладают перечисления с областью видимости?

Перечисления с областью видимости - `enum class` - обладают собственной областью видимости. Это свойство уменьшает риск возникновения ошибок вследствие одинаковых названий различных сущностей