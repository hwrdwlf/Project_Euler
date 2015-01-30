<?php

$m = 1;
$n = 2;
$temp = array();
$sum = 0;

while($m < 1000000 | $n < 1000000){
   $prime1 = gmp_nextprime($m);
   $prime2 = gmp_nextprime($n);

   $sum = $sum + $prime1 + $prime2;
   $m += 2; $n += 2;
}

echo "Sum: $sum\n";




?>
