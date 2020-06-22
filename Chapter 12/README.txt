Write  a  function  to  insert  a  new  word  into  the  concordance  list  described  in the picture. 
The function should take a pointer to the list pointer and a string as  its arguments. 
The string is assumed to contain a single word. If the word does not  already exist in the list, 
it should be copied into dynamically allocated memory and  then inserted. 
The function should return true if the string was inserted; and false if the string already existed in the list, 
did not begin with a letter, or if anything else  went wrong. The function should maintain the primary list in order by the letter of the node 
and the secondary lists in order by the words. 