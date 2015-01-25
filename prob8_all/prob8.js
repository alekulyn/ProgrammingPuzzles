// The four adjacent digits in the 1000-digit number (below) that have the greatest product are 9 * 9 * 8 * 9 = 5832.
// Find the thirteen adjacent digits in the 1000-digit number that have the greatest product. What is the value of this product?

var theNUMBER =
"73167176531330624919225119674426574742355349194934\
96983520312774506326239578318016984801869478851843\
85861560789112949495459501737958331952853208805511\
12540698747158523863050715693290963295227443043557\
66896648950445244523161731856403098711121722383113\
62229893423380308135336276614282806444486645238749\
30358907296290491560440772390713810515859307960866\
70172427121883998797908792274921901699720888093776\
65727333001053367881220235421809751254540594752243\
52584907711670556013604839586446706324415722155397\
53697817977846174064955149290862569321978468622482\
83972241375657056057490261407972968652414535100474\
82166370484403199890008895243450658541227588666881\
16427171479924442928230863465674813919123162824586\
17866458359124566529476545682848912883142607690042\
24219022671055626321111109370544217506941658960408\
07198403850962455444362981230987879927244284909188\
84580156166097919133875499200524063689912560717606\
05886116467109405077541002256983155200055935729725\
71636269561882670428252483600823257530420752963450"

var magic_num = parseInt(prompt("How many digits should I look for?"));
var zeroIndices = [];
var finalAnswer = 0;

elimZeroRanges();
calGrtstPrduct();

alert(finalAnswer);

function elimZeroRanges ()
{
	// Find zero ranges and splice
	theNUMBER = theNUMBER.split("0");
	var NUM_len = theNUMBER.length; // CACHE
	for (var i = 0; i < NUM_len; i++)
	{
		if (theNUMBER[i].length < magic_num)
		{
			theNUMBER.splice(i, 1);
			i--;
			NUM_len--;
		}
	}
	theNUMBER = theNUMBER.join("0");
	NUM_len = theNUMBER.length - 1; // CACHE
	
	// Mark remaining zero indices
	var zeroIndices_len = 0, nextIndex = theNUMBER.indexOf("0");
	for (; nextIndex !== -1; zeroIndices_len++)
	{
		zeroIndices.push(nextIndex);
		nextIndex = theNUMBER.indexOf("0", zeroIndices[zeroIndices_len] + 1);  // Putting this in afterthought step increases clutter.
	}
}

function calGrtstPrduct ()
{
	var NUM_len = theNUMBER.length - (magic_num - 1); // CACHE  // Check that 1. Might be unnecessary/incorrect.
	for (var i = 0; i < NUM_len; i++)
	{
		if (zeroIndices[0] - i < magic_num)
		{
			i = zeroIndices[0];
			zeroIndices.splice(0, 1);
			continue;
		}
		count(i);
	}
}

function count (start)
{
	var end = start + magic_num;
	var result = 1;
	for (; start < end; start++)
	{
		result *= parseInt(theNUMBER[start]);
	}
	finalAnswer = Math.max(finalAnswer, result)
}