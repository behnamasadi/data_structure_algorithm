# Finite State Machine (Finite Automata)

It is the simplest model of computation and has limited memory.

Without output
1) DFA: Deterministic Finite Automata

State with input arrowInitial State
Double Circle: Final/ termination State
(Q, Σ, q0, F, 𝛿 )
Q: Set of all states
q0: Start/ Initial State
Σ: A Finite set of input 
F: Set of Final State
𝛿: Transition Function that maps (QxΣ) -> Q


```
    →A ◯  ⤺   ◯ B      
          ⤻
     ↓ ↑       ↓ ↑
     C ◯  ⤺   ⦾ D
          ⤻
```
Q: {A, b, C, D}
q0: Start/ Initial State
Σ: {0,1}
F: {D}
𝛿:  
 
|   | 0 | 1 |
|---|---|---|
| A | C | B |
| B | D | A |
| C | A | D |
| D | B | C |
 


2) NFA: Non Deterministic Finite Automata
In NFA, given the current state, there could be multiple next state


```
          1 
    A  ◯  →  ◯ B 
      0 ↻   
    Є  ↓  ↘0   
    C  ◯     ⦾   D
```


3) Є-NFA: Non Deterministic Finite Automata

With output 
1) Moore Machine
2) Mealy Machine



Refs: [1](https://en.wikipedia.org/wiki/Deterministic_finite_automaton)
