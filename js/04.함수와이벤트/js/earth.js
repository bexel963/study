
var $earth = null;

$(document).ready(function(){
    initialize();
    event();
});

// 전역변수 초기화
function initialize(){
    $earth = $("#earth");
}
// 이벤트와 관련된 내용을 함수로 등록
function event(){
    $("#btnStart").click(function(){
        var x = parseInt($("#txtX").val());
        var y = parseInt($("#txtY").val());
        moveEarth(x, y);
    })
    
    function moveEarth(x, y){
        if((x>=0 && x<=500) && (y>=0 && y<=500)){
            $earth.css({
                left : x,
                top : y
            });
        }else{
            alert("입력된 값이 범위를 벗어났습니다.");
        }
    }
}







