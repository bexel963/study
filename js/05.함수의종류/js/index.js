$(document).ready(function(){
    // 탭 메뉴 코드 실행될 수 있도록 함수 호출
    tabMenu("#tabmenu1");
});

function tabMenu(selector) {
    var $tabMenu = null;
    var $menuItems = null;
    var $selectedMenuItem = null;

    init(selector);
    initEvent();

    // 요소 초기화
    function init(selector) {
        $tabMenu = $(selector);
        $menuItems = $tabMenu.find("li");   // 6개의 웹요소인 li태그를 배열로 받는다.
    }
    // 이벤트 초기화 및 등록
    function initEvent() {
        $menuItems.click(function(){
            setSelectItem($(this));     // 현재 선택된 li라는 웹 요소를 매개변수로 지정하고 있다.
        });
    }

    // 선택된 메뉴 아이템을 만들어주는 함수
    function setSelectItem($item) {
        // 선택된 메뉴가 있다면
        if($selectedMenuItem != null){
            // 그 메뉴의 select를 제거
            $selectedMenuItem.removeClass("select");
        }
        // 매개변수로 넘어온 선택된 아이템을 대입
        $selectedMenuItem = $item;
        // 그 메뉴에 select를 추가
        $selectedMenuItem.addClass("select");

        $("#info").html($selectedMenuItem.index());
    }
}