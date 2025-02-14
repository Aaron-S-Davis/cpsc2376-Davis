Fix error in sumRange function

i<end changed to i<=end. The for loop in sumRange was iterating one less 
time than it should havebecause it was set to stop before the end variable 
instead of at the end variable. 


Fix containsNegative function for loop iteration

Changed i<=numbers.size() to i<numbers.size(). For loop was exiting too late,
if statement was evaluating an uninitialized segment of the numbers vector.


Fix containsNegative function if statement logic error

Changed if(numbers[i]>0) to if(numbers[i]<0). If statement was returning true
when evaluated number was positive rather than when it was negative


Fix findMax function for loop logic error

Changed i<=numbers.size() to i<numbers.size(). For loop was exiting too late,
if statement was evaluating an uninitialized segment of the numbers vector.
