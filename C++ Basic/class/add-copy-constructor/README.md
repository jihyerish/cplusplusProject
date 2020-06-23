# Add a copy constructor to an existing class

Given the `Dog` class defined in `Dog.h`, add a copy constructor.

Also, display "Copy constructor" to `cout` in the body of your copy constructor.

The copy constructor should allow to create `Dog` objects as follows:

```
Dog spot {"Spot", 5};
Dog twin {spot};
```