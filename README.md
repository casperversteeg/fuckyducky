# fuckyducky

Basically, I have the inheritance graph:
```
Base
 |
 |-- A<T>
 |    |
 |    |- DerivA<T>
 |
 |-- B<T,U>
     |
     |- DerivB<T,U>
```
I want to create a type helper `what_type_t` which will be passed either a `DerivA<T>` or `DerivB<T,U>` (of which there will be many) which will either return the type `T` if it is `std::arithmetic`, or `TypeInvalid` if not, recursing through as many nested `DerivA` and `DerivB` as necessary to get to a final type. 

The most logical thing, to me, is to identify the many `DerivA` and `DerivB` by their base classes `A` and `B`, which is what the code is currently attempting to do. However, in the template specializations of `WhatType`:

```
template <typename T> struct WhatType<A<T>> {
  using type = typename WhatType<T>::type;
};

template <typename T, typename U> struct WhatType<B<T, U>> {
  using type =
      typename WhatType<std::common_type_t<typename WhatType<T>::type,
                                           typename WhatType<U>::type>>::type;
};
```

the types `A` and `B` will not be matched with `DerivA` and `DerivB` respectively, even though I very much would like it to...
