function showPrice(){
    var price = document.querySelector("#originalPrice").value;
    var rate = document.querySelector("#rate").value;

    if(price > 0 && rate > 0){
        var savedPrice = price * (rate/100);
        var result = price - savedPrice;
    }
    
    document.querySelector("#showResult").innerHTML = 
    "상품의 원래 가격은 " + price + "원 이고, 할인율은 " + rate + " % 입니다. "
    + savedPrice + "원을 절약한 " + result + "원에 살 수 있습니다.";
}