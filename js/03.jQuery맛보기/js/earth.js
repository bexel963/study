$(document).ready(function(){
    var $earth = $("#earth");           // 지구 이미지 웹요소(노드)를 찾아서 변수에 저장
    $("#btnStart").click(function(){    // 버튼에 이벤트 등록
        $earth.animate({
            left : "480px"
        }, 1000);
    })
})
// 버튼을 클릭하면 콜백함수가 호출된다.