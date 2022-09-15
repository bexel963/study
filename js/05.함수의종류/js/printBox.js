var count = 0;        // 전역변수
var $container = null;  // 전역변수

$(document).ready(function(){

    $container = $("#container");

    // append()는 문자열을 붙여서 출력하는 함수.
    $container.append("<p>" + count + " 안녕하세요. 반갑습니다. </p>");
    count++;

    // 버튼이 클릭 되면 익명함수를 실행하여 지속적으로 글자를 붙여서 출력하게 된다.
    $("#btnPrint").on("click", function(){
        $container.append("<p>" + count + " 안녕하세요. 반갑습니다. </p>");
        count++;
    })
})