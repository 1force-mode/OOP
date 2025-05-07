Диаграмма классов (3 пункт задания)
```plaintext
┌─────────────────────────────────┐
│        TrainStack<T>            │
├─────────────────────────────────┤
│ - data: std::vector<T>          │
├─────────────────────────────────┤
│ + push(value: const T&): void   │
│ + pop(): void                   │
│ + top(): T&                     │
│ + top() const: const T&         │
│ + empty() const: bool           │
│ + size() const: size_t          │
└─────────────────────────────────┘

┌─────────────────────────────────┐
│            Train                │
├─────────────────────────────────┤
│ + enum WagonType {              │
│     Wood,                       │
│     Steel                       │
│   }                             │
├─────────────────────────────────┤
│ - wagons: TrainStack<WagonType> │
├─────────────────────────────────┤
│ + createTrain(wagonCount: int): │
│           void                  │
│ + sortTrains(): void           │
│ + printTrain(title: const       │
│   std::string&, train: const    │
│   TrainStack<WagonType>&): void │
│ + printOriginalTrain(): void    │
└─────────────────────────────────┘
```
