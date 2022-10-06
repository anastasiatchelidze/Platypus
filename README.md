# Platypus

creates a class modeled after platypus which has weight, age, name initial, gender and attributes that indicate whether they are alive and/or mutant or not, and also methods which correspond to platypus’ real life events, such as, eating, aging, fighting and hatching.

Method age_me() increments platypus’ age if it’s alive, otherwise, error message is displayed. There is 2% chance that platypus will become a mutant which is done by as followed: random numbers from 1 to 50 are generated and if the selected number (stored in temporary variable – temp) equals to 2, then platypus becomes mutant. Thus, the chance of becoming mutant is 1 from 50 which is same as 2 percent. Also, if weight is less than 10, the chance of platypus’ death is 10*weight, otherwise, if it’s more or equal to 10, platypus dies (alive gets the value false, because chance of death is 100%).

Function fight gets another Platypus as a parameter (which it is supposed to fight). It only works if both of the platypuses are alive. Random integer from 1-100 interval is obtained and if it’s less than the fight ratio (calling platypus’ weight divided by passed platypus’ weight and multiplied by 50) then again, by using if-else condition calling platypus survives and other one dies, if it’s more or equal, then vice-versa.

Method eat() increases the weight by random amount from 0.1%-5% of platypus’ current weight. Firstly, temporary variable ‘temp’ is created. Its type is double to avoid integer by integer division which truncates the result. Since the interval is from 0.1 – 5, randomly obtained value is divided by 10. Weight increases by temp/10 percentage.

In the function hatch() gender is chosen randomly: random value 0 or 1 is obtained by rand() and respectively, gender gets assigned ‘F’ or ‘M’. New platypus object is created with explicit-value constructor.
