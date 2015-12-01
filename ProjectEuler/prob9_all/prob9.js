// A Pythagorean triplet is a set of three natural numbers, a < b < c, for which,
// a^2 + b^2 = c^2
// For example, 3^2 + 4^2 = 9 + 16 = 25 = 5^2.
// There exists exactly one Pythagorean triplet for which a + b + c = 1000.
// Find the product abc.


// https://en.wikipedia.org/wiki/Formulas_for_generating_Pythagorean_triples
// http://www.mathsisfun.com/numbers/pythagorean-triples.html

var a, b, c, tripletTotal = 1000;
var c_min = Math.ceil((Math.sqrt(2) - 1) * tripletTotal), c_max = tripletTotal/2;  // (sqrt(2) - 1) equals (c / (a + b + c)) in an isosceles right triangle 

// Find all numbers in [c_min, c_max) that can be reached via below methods
/* Dickson method
if (r^2 = 2st)
	then (a = r + s), (b = r + t), (c = r + s + t)
*/
/* MathisFun method
a = n^2 - m^2
b = 2nm
c = n^2 + m^2
*/

if (true)
{
	var MathIsFun = new MathIsFun_technique();
	MathIsFun.popSquares();
	alert(MathIsFun.squares);
} else if (false)
{
}


function MathIsFun_technique ()
{
	this.squares = [];
	this.popSquares = function ()
	{
		var i, j;
		for (i = 1, j = Math.floor(Math.sqrt(c_max)); i <= j; i++)
		{
			// this.squares.push.call(this.caller, Math.pow(i, 2)); // context is wrong
			this.squares.push(Math.pow(i, 2));
		}
	};	
}

function LeonardDickson_technique ()
{
}