# Linked Lists

## Linear linked List

```
---------    ---------    ---------
| Value |    | Value |    | Value |
|  ---  |    |  ---  |    |  ---  |
|  next-|--> |  next-|--> |  next-|--> nullptr
---------    ---------    ---------
```


## Circular linked List

It has two representation:
```
 ---------------------------------------
| Head                                 | 
↓                                                        | 
---------    ---------    ---------    |
| Value |    | Value |    | Value |    | 
|  ---  |    |  ---  |    |  ---  |    |
|  next-|--> |  next-|--> |  next-|----| 
---------    ---------    ---------
```

```
             ---------------------------
Head         |                         | 
  ↓               ↓                                     | 
---------    ---------    ---------    |
| Value |    | Value |    | Value |    | 
|  ---  |    |  ---  |    |  ---  |    |
|  next-|--> |  next-|--> |  next-|----| 
---------    ---------    ---------

```


## Double linked List

```
---------    ---------    ---------
| Value |    | Value |    | Value |
|  ---  |    |  ---  |    |  ---  |
|  next-|--> |  next-|--> |  next-|--> nullptr
|  pre  |<-- |  next |<-- |  pre  |
---------    ---------    ---------
```

