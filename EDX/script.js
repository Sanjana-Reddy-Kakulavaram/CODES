function compute()
{
    let z = 5;
    let p = document.getElementById("principal").value;
    if(p <= 0)
    {
        alert("Enter a Positive Number");
        document.getElementById("principal").focus();
        return;
    }
    let q = document.getElementById("rate").value;
    let r = document.getElementById("years").value;
    let intrest = ((p*q*r)/100);
    document.getElementById("amount").innerHTML = "If you deposit ";
    document.getElementById("rate2").innerHTML = "at an intrest rate of ";
    document.getElementById("result").innerHTML = "You will receive an amount of ";
    document.getElementById("year").innerHTML = "in the year ";
    document.getElementById("amount2").innerHTML = p + ",";
    document.getElementById("rate3").innerHTML = q + "%.";
    document.getElementById("result2").innerHTML = (intrest) + ",";
    document.getElementById("year2").innerHTML = (2021 + parseInt(r));
}
function showVal(val)
{
    document.getElementById("value").innerHTML = val + "%";
}