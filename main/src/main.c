
/**
 * @file main
 *
 */

/*********************
 *      INCLUDES
 *********************/
#define _DEFAULT_SOURCE /* needed for usleep() */

#include <stdlib.h>
#include <unistd.h>

#define SDL_MAIN_HANDLED /*To fix SDL's "undefined reference to WinMain" issue*/

#include "SDL2/SDL.h"
#include "demos/lv_demos.h"
#include "examples/lv_examples.h"
#include "lv_drivers/display/monitor.h"
#include "lv_drivers/indev/keyboard.h"
#include "lv_drivers/indev/mouse.h"
#include "lv_drivers/indev/mousewheel.h"
#include "lvgl/lvgl.h"
#include "testapp/gui_guider.h"
#include "ui/ui.h"
// #include "3d_printer/test_ui.h"

lv_ui guider_ui;
#if 0
const char *test_pro_roller = "北京市\n天津市\n河北省\n山西省\n内蒙古\n辽宁省\n吉林省\n黑龙江省\n上海市\n"
                         "江苏省\n浙江省\n安徽省\n福建省\n江西省\n山东省\n河南省\n湖北省\n湖南省\n"
                         "广东省\n广西\n海南省\n重庆市\n四川省\n贵州省\n云南省\n西藏\n陕西省\n甘肃省\n"
                         "青海省\n宁夏\n新疆\n台湾省\n香港\n澳门";

// 北京
#define beijing_roller "北京市"
// 天津
#define tianjin_roller "天津市"
// 河北
#define hebei_roller "石家庄市\n唐山市\n秦皇岛市\n邯郸市\n邢台市\n保定市\n张家口市\n承德市\n沧州市\n廊坊市\n衡水市"
// 山西
#define shanxi_roller "太原市\n大同市\n阳泉市\n长治市\n晋城市\n朔州市\n晋中市\n运城市\n忻州市\n临汾市\n吕梁市"
// 内蒙
#define neimeng_roller "呼和浩特市\n包头市\n乌海市\n赤峰市\n通辽市\n鄂尔多斯市\n呼伦贝尔市\n巴彦淖尔市\n乌兰察布市\n兴安盟\n锡林郭勒盟\n阿拉善盟"
// 辽宁
#define liaoning_roller "沈阳市\n大连市\n鞍山市\n抚顺市\n本溪市\n丹东市\n锦州市\n营口市\n阜新市\n辽阳市\n盘锦市\n铁岭市\n朝阳市\n葫芦岛市"
// 吉林
#define jilin_roller "长春市\n吉林市\n四平市\n辽源市\n通化市\n白山市\n松原市\n白城市\n延边朝鲜族自治州"
// 黑龙江
#define heilongjinag_roller "哈尔滨市\n齐齐哈尔市\n鸡西市\n鹤岗市\n双鸭山市\n大庆市\n伊春市\n佳木斯市\n七台河市\n牡丹江市\n黑河市\n绥化市\n大兴安岭地区"
// 上海
#define shanghai_roller "上海市"
// 江苏省
#define jiangsu_roller "南京市\n无锡市\n徐州市\n常州市\n苏州市\n南通市\n连云港市\n淮安市\n盐城市\n扬州市\n镇江市\n泰州市\n宿迁市"
// 浙江省
#define zhejiang_roller "杭州市\n宁波市\n温州市\n嘉兴市\n湖州市\n绍兴市\n金华市\n衢州市\n舟山市\n台州市\n丽水市"
// 安徽省
#define anhui_roller "合肥市\n芜湖市\n蚌埠市\n淮南市\n马鞍山市\n淮北市\n铜陵市\n安庆市\n黄山市\n滁州市\n阜阳市\n宿州市\n六安市\n亳州市\n池州市\n宣城市"
// 福建省
#define fujian_roller "福州市\n厦门市\n莆田市\n三明市\n泉州市\n漳州市\n南平市\n龙岩市\n宁德市"
// 江西省
#define jiangxi_roller "南昌市\n景德镇市\n萍乡市\n九江市\n新余市\n鹰潭市\n赣州市\n吉安市\n宜春市\n抚州市\n上饶市"
// 山东省
#define shandong_roller "济南市\n青岛市\n淄博市\n枣庄市\n东营市\n烟台市\n潍坊市\n济宁市\n泰安市\n威海市\n日照市\n临沂市\n德州市\n聊城市\n滨州市\n菏泽市"
// 河南省
#define henan_roller "开封市\n洛阳市\n平顶山市\n安阳市\n鹤壁市\n新乡市\n焦作市\n濮阳市\n许昌市\n漯河市\n三门峡市\n南阳市\n商丘市\n信阳市\n周口市\n驻马店市\n济源市"
// 湖北省
#define hubei_roller "武汉市\n黄石市\n十堰市\n宜昌市\n襄阳市\n鄂州市\n荆门市\n孝感市\n荆州市\n黄冈市\n咸宁市\n随州市\n恩施土家族苗族自治州\n仙桃市\n潜江市\n天门市\n神农架林区"
// 湖南省
#define hunan_roller "长沙市\n株洲市\n湘潭市\n衡阳市\n邵阳市\n岳阳市\n常德市\n张家界市\n益阳市\n郴州市\n永州市\n怀化市\n娄底市\n湘西土家族苗族自治州"
// 广东省
#define guangdong_roller "广州市\n韶关市\n深圳市\n珠海市\n汕头市\n佛山市\n江门市\n湛江市\n茂名市\n肇庆市\n惠州市\n梅州市\n汕尾市\n河源市\n阳江市\n清远市\n东莞市\n中山市\n潮州市\n揭阳市\n云浮市"
// 广西壮族自治区
#define guangxi_roller "南宁市\n柳州市\n桂林市\n梧州市\n北海市\n防城港市\n钦州市\n贵港市\n玉林市\n百色市\n贺州市\n河池市\n来宾市\n崇左市"
// 海南省
#define hainan_roller "海口市\n三亚市\n三沙市\n儋州市\n五指山市\n琼海市\n文昌市\n万宁市\n东方市\n定安县\n屯昌县\n澄迈县\n临高县\n白沙黎族自治县\n昌江黎族自治县\n乐东黎族自治县\n陵水黎族自治县\n保亭黎族苗族自治县\n琼中黎族苗族自治县"
// 重庆市
#define chongqing_roller "重庆市"
// 四川省
#define sichuan_roller "成都市\n自贡市\n攀枝花市\n泸州市\n德阳市\n绵阳市\n广元市\n遂宁市\n内江市\n乐山市\n南充市\n眉山市\n宜宾市\n广安市\n达州市\n雅安市\n巴中市\n资阳市\n阿坝藏族羌族自治州\n甘孜藏族自治州\n凉山彝族自治州"
// 贵州省
#define guizhou_roller "贵阳市\n六盘水市\n遵义市\n安顺市\n毕节市\n铜仁市\n黔西南布依族苗族自治州\n黔东南苗族侗族自治州\n黔南布依族苗族自治州"
// 云南省
#define yunnan_roller "昆明市\n曲靖市\n玉溪市\n保山市\n昭通市\n丽江市\n普洱市\n临沧市\n楚雄彝族自治州\n红河哈尼族彝族自治州\n文山壮族苗族自治州\n西双版纳傣族自治州\n大理白族自治州\n德宏傣族景颇族自治州\n怒江傈僳族自治州\n迪庆藏族自治州"
// 西藏自治区
#define xizang_roller "拉萨市\n日喀则市\n昌都市\n林芝市\n山南市\n那曲市\n阿里地区"
// 陕西省
#define shanxi3_roller "西安市\n铜川市\n宝鸡市\n咸阳市\n渭南市\n延安市\n汉中市\n榆林市\n安康市\n商洛市"
// 甘肃省
#define gansu_roller "兰州市\n嘉峪关市\n金昌市\n白银市\n天水市\n武威市\n张掖市\n平凉市\n酒泉市\n庆阳市\n定西市\n陇南市\n临夏回族自治州\n甘南藏族自治州"
// 青海省
#define qinghai_roller "西宁市\n海东市\n海北藏族自治州\n黄南藏族自治州\n海南藏族自治州\n果洛藏族自治州\n玉树藏族自治州\n海西蒙古族藏族自治州"
// 宁夏回族自治区
#define ningxia_roller "银川市\n石嘴山市\n吴忠市\n固原市\n中卫市"
// 新疆维吾尔自治区
#define xingjiang_roller "乌鲁木齐市\n克拉玛依市\n吐鲁番市\n哈密市\n昌吉回族自治州\n博尔塔拉蒙古自治州\n巴音郭楞蒙古自治州\n阿克苏地区\n克孜勒苏柯尔克孜自治州\n喀什地区\n和田地区\n伊犁哈萨克自治州\n塔城地区\n阿勒泰地区\n胡杨河市\n石河子市\n阿拉尔市\n图木舒克市\n五家渠市\n北屯市\n铁门关市\n双河市\n可克达拉市\n昆玉市\n新星市"
// 台湾省
#define taiwan_roller "台北市\n高雄市\n新北市\n台中市\n台南市\n桃园市\n基隆市\n新竹市\n嘉义市\n新竹县\n宜兰县\n苗栗县\n彰化县\n云林县\n南投县\n嘉义县\n屏东县\n台东县\n花莲县\n澎湖县"
// 香港特别行政区
#define xianggang_roller "香港"
// 澳门特别行政区
#define aomen_roller "澳门"

const char *prov_list[] = {
    beijing_roller,
    tianjin_roller,
    hebei_roller,
    shanxi_roller,
    neimeng_roller,
    liaoning_roller,
    jilin_roller,
    heilongjinag_roller,
    shanghai_roller,
    jiangsu_roller,
    zhejiang_roller,
    anhui_roller,
    fujian_roller,
    jiangxi_roller,
    shandong_roller,
    henan_roller,
    hubei_roller,
    hunan_roller,
    guangdong_roller,
    guangxi_roller,
    hainan_roller,
    chongqing_roller,
    sichuan_roller,
    guizhou_roller,
    yunnan_roller,
    xizang_roller,
    shanxi3_roller,
    gansu_roller,
    qinghai_roller,
    ningxia_roller,
    xingjiang_roller,
    taiwan_roller,
    xianggang_roller,
    aomen_roller};
// const char *test_beijing_roller = "北京市";
// // 天津
// const char *test_tianjin_roller = "天津市";
// // 河北
// const char *test_hebei_roller = "石家庄市\n唐山市\n秦皇岛市\n邯郸市\n邢台市\n保定市\n张家口市\n承德市\n沧州市\n廊坊市\n衡水市\n";
// // 山西
// const char *test_shanxi_roller = "太原市\n大同市\n阳泉市\n长治市\n晋城市\n朔州市\n晋中市\n运城市\n忻州市\n临汾市\n吕梁市\n";
// // 内蒙
// const char *test_neimeng_roller = "呼和浩特市\n包头市\n乌海市\n赤峰市\n通辽市\n鄂尔多斯市\n呼伦贝尔市\n巴彦淖尔市\n乌兰察布市\n兴安盟\n锡林郭勒盟\n阿拉善盟\n";
#endif

// extern const char *prov_list[];

static void hal_init(void);

static int tick_thread(void *data);

static void _imgbtn1_event_cb(lv_event_t *e)
{
    printf("_imgbtn1_event_cb\n");
}

void lv_ex_imgbtn_1(void)
{
    LV_IMG_DECLARE(light_on);
    LV_IMG_DECLARE(light_off);

    /*Darken the button when pressed*/
    static lv_style_t style;

    if(style.prop_cnt > 1)
        lv_style_reset(&style);
    else
        lv_style_init(&style);
    lv_style_set_img_recolor_opa(&style, LV_OPA_30);
    lv_style_set_img_recolor(&style, lv_color_black());

    /*Create an Image button*/
    lv_obj_t *imgbtn1 = lv_imgbtn_create(lv_scr_act());
    lv_imgbtn_set_src(imgbtn1, LV_IMGBTN_STATE_RELEASED, NULL, &light_off, NULL);
    lv_imgbtn_set_src(imgbtn1, LV_IMGBTN_STATE_PRESSED, NULL, &light_off, NULL);
    lv_imgbtn_set_src(imgbtn1, LV_IMGBTN_STATE_CHECKED_RELEASED, NULL, &light_on, NULL);
    lv_imgbtn_set_src(imgbtn1, LV_IMGBTN_STATE_CHECKED_PRESSED, NULL, &light_on, NULL);
    lv_obj_set_size(imgbtn1, 58, 58);
    lv_obj_set_pos(imgbtn1, 0, 0);
    // lv_obj_set_y(imgbtn1, 0);
    lv_obj_set_align(imgbtn1, LV_ALIGN_CENTER);
    // lv_imgbtn_set_checkable(imgbtn1, true);
    lv_obj_add_style(imgbtn1, &style, LV_STATE_PRESSED);
    // lv_obj_align(imgbtn1, LV_ALIGN_CENTER, 0, 0);
    lv_obj_add_flag( imgbtn1, LV_OBJ_FLAG_CHECKABLE );   /// Flags
    lv_obj_clear_flag( imgbtn1, LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_GESTURE_BUBBLE | LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM | LV_OBJ_FLAG_SCROLL_CHAIN );    /// Flags
    lv_obj_set_scrollbar_mode(imgbtn1, LV_SCROLLBAR_MODE_OFF);
    lv_obj_add_event_cb(imgbtn1, _imgbtn1_event_cb, LV_EVENT_CLICKED, imgbtn1);

    /*Create a label on the Image button*/
    // lv_obj_t * label = lv_label_create(imgbtn1);
    // lv_label_set_text(label, "Button");
}

void lv_example_barcode_1(void)
{
    lv_color_t bg_color = lv_palette_lighten(LV_PALETTE_LIGHT_BLUE, 5);
    lv_color_t fg_color = lv_palette_darken(LV_PALETTE_BLUE, 4);

    lv_obj_t * barcode = lv_barcode_create(lv_scr_act());
    lv_obj_set_height(barcode, 50);
    lv_obj_center(barcode);

    /*Set color*/
    lv_barcode_set_dark_color(barcode, (lv_color32_t)lv_color_to32(lv_color_hex(0x000000)));
    lv_barcode_set_light_color(barcode, (lv_color32_t)lv_color_to32(lv_color_hex(0xffffff)));

    /*Add a border with bg_color*/
    lv_obj_set_style_border_color(barcode, lv_color_hex(0xffffff), 0);
    lv_obj_set_style_border_width(barcode, 5, 0);

    /*Set data*/
    lv_barcode_update(barcode, "");
}

void lv_example_grid_my(void)
{
    static lv_coord_t col_dsc[] = {LV_GRID_CONTENT, LV_GRID_FR(1), LV_GRID_CONTENT, LV_GRID_TEMPLATE_LAST};
    static lv_coord_t row_dsc[] = {50, 50, 50, LV_GRID_TEMPLATE_LAST};

    /*Create a container with grid*/
    lv_obj_t * cont = lv_obj_create(lv_scr_act());
    lv_obj_set_grid_dsc_array(cont, col_dsc, row_dsc);
    lv_obj_set_size(cont, 300, 220);
    lv_obj_center(cont);

    lv_obj_t * label;
    lv_obj_t * obj;

    /*Cell to 0;0 and align to to the start (left/top) horizontally and vertically too*/
    obj = lv_obj_create(cont);
    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
    lv_obj_set_grid_cell(obj, LV_GRID_ALIGN_START, 0, 1,
                         LV_GRID_ALIGN_START, 0, 1);
    label = lv_label_create(obj);
    lv_label_set_text(label, "c0, r0");

    /*Cell to 1;0 and align to to the start (left) horizontally and center vertically too*/
    obj = lv_obj_create(cont);
    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
    lv_obj_set_grid_cell(obj, LV_GRID_ALIGN_START, 0, 1,
                         LV_GRID_ALIGN_STRETCH, 1, 2);
    label = lv_label_create(obj);
    lv_label_set_text(label, "c0, r1");

    /*Cell to 2;0 and align to to the start (left) horizontally and end (bottom) vertically too*/
    // obj = lv_obj_create(cont);
    // lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
    // lv_obj_set_grid_cell(obj, LV_GRID_ALIGN_START, 2, 1,
    //                      LV_GRID_ALIGN_END, 0, 1);
    // label = lv_label_create(obj);
    // lv_label_set_text(label, "c2, r0");

    // /*Cell to 1;1 but 2 column wide (span = 2).Set width and height to stretched.*/
    // obj = lv_obj_create(cont);
    // lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
    // lv_obj_set_grid_cell(obj, LV_GRID_ALIGN_STRETCH, 1, 2,
    //                      LV_GRID_ALIGN_STRETCH, 1, 1);
    // label = lv_label_create(obj);
    // lv_label_set_text(label, "c1-2, r1");

    // /*Cell to 0;1 but 2 rows tall (span = 2).Set width and height to stretched.*/
    // obj = lv_obj_create(cont);
    // lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
    // lv_obj_set_grid_cell(obj, LV_GRID_ALIGN_STRETCH, 0, 1,
    //                      LV_GRID_ALIGN_STRETCH, 1, 2);
    // label = lv_label_create(obj);
    // lv_label_set_text(label, "c0\nr1-2");
}

#if 0


void ui_Screen1_screen_init(void)
{

lv_obj_t *ui_Screen1;
lv_obj_t *ui_Panel2;
lv_obj_t *ui_Label2;
lv_obj_t *ui_Roller2;
lv_obj_t *ui_Roller1;
lv_obj_t *ui_Slider2;

ui_Screen1 = lv_obj_create(lv_scr_act());
lv_obj_set_width( ui_Screen1, 480);
lv_obj_set_height( ui_Screen1, 480);
lv_obj_clear_flag( ui_Screen1, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_bg_color(ui_Screen1, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_Screen1, 10, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Panel2 = lv_obj_create(ui_Screen1);
lv_obj_set_width( ui_Panel2, 318);
lv_obj_set_height( ui_Panel2, 276);
lv_obj_set_align( ui_Panel2, LV_ALIGN_CENTER );
lv_obj_clear_flag( ui_Panel2, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_border_color(ui_Panel2, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT );

ui_Label2 = lv_label_create(ui_Panel2);
lv_obj_set_width( ui_Label2, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Label2, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Label2, -118 );
lv_obj_set_y( ui_Label2, -1 );
lv_obj_set_align( ui_Label2, LV_ALIGN_CENTER );
lv_label_set_text(ui_Label2,"Location");
// lv_obj_set_style_pad_all()

ui_Roller2 = lv_roller_create(ui_Panel2);
lv_roller_set_options( ui_Roller2, "Option 1\nOption 2\nOption 5", LV_ROLLER_MODE_NORMAL );
lv_obj_set_height( ui_Roller2, 135);
lv_obj_set_width( ui_Roller2, LV_SIZE_CONTENT);  /// 1
lv_obj_set_x( ui_Roller2, -19 );
lv_obj_set_y( ui_Roller2, -4 );
lv_obj_set_align( ui_Roller2, LV_ALIGN_CENTER );
// lv_obj_set_style_border_color(ui_Roller2, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
lv_obj_set_style_border_opa(ui_Roller2, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
// lv_obj_set_style_pad_gap(ui_Roller2, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
lv_obj_set_style_outline_width(ui_Roller2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
// lv_obj_set_style_pad_ver

ui_Roller1 = lv_roller_create(ui_Panel2);
lv_roller_set_options( ui_Roller1, "Option 1\nOption 2\nOption 3", LV_ROLLER_MODE_NORMAL );
lv_obj_set_height( ui_Roller1, 135);
lv_obj_set_width( ui_Roller1, LV_SIZE_CONTENT);  /// 1
lv_obj_set_x( ui_Roller1, 93 );
lv_obj_set_y( ui_Roller1, -4 );
lv_obj_set_align( ui_Roller1, LV_ALIGN_CENTER );
// lv_obj_set_style_border_color(ui_Roller1, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_border_opa(ui_Roller1, 0, LV_PART_MAIN| LV_STATE_DEFAULT);

// ui_Slider2 = lv_slider_create(ui_Screen1);
// lv_obj_set_width( ui_Slider2, 150);
// lv_obj_set_height( ui_Slider2, 10);
// lv_obj_set_x( ui_Slider2, -54 );
// lv_obj_set_y( ui_Slider2, -179 );
// lv_obj_set_align( ui_Slider2, LV_ALIGN_CENTER );
// lv_obj_set_style_bg_color(ui_Slider2, lv_color_hex(0xAFAFAF), LV_PART_MAIN | LV_STATE_DEFAULT );
// lv_obj_set_style_bg_opa(ui_Slider2, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
// lv_obj_set_style_border_color(ui_Slider2, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
// lv_obj_set_style_border_opa(ui_Slider2, 255, LV_PART_MAIN| LV_STATE_DEFAULT);

// lv_obj_set_style_bg_color(ui_Slider2, lv_color_hex(0xF68F3B), LV_PART_INDICATOR | LV_STATE_DEFAULT );
// lv_obj_set_style_bg_opa(ui_Slider2, 255, LV_PART_INDICATOR| LV_STATE_DEFAULT);

// lv_obj_set_style_radius(ui_Slider2, 5, LV_PART_KNOB| LV_STATE_DEFAULT);
// lv_obj_set_style_bg_color(ui_Slider2, lv_color_hex(0xFFFFFF), LV_PART_KNOB | LV_STATE_DEFAULT );
// lv_obj_set_style_bg_opa(ui_Slider2, 255, LV_PART_KNOB| LV_STATE_DEFAULT);

}


static void mask_event_cb1(lv_event_t * e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t * obj = lv_event_get_target(e);
    lv_obj_t * obj_r2 = lv_event_get_user_data(e);

    static int16_t mask_top_id = -1;
    static int16_t mask_bottom_id = -1;

    if(code == LV_EVENT_VALUE_CHANGED) {
        char buf[32];
        lv_roller_get_selected_str(obj, buf, sizeof(buf));
        uint16_t index = lv_roller_get_selected(obj);
        LV_LOG_USER("Selected prov: %s, cnt: %d\n", buf, index);

        lv_roller_set_options(obj_r2,
                        prov_list[index],
                        LV_ROLLER_MODE_NORMAL);
        
    }
    else if(code == LV_EVENT_COVER_CHECK) {
        lv_event_set_cover_res(e, LV_COVER_RES_MASKED);
    }
    else if(code == LV_EVENT_DRAW_MAIN_BEGIN) {
        /* add mask */
        const lv_font_t * font = lv_obj_get_style_text_font(obj, LV_PART_MAIN);
        lv_coord_t line_space = lv_obj_get_style_text_line_space(obj, LV_PART_MAIN);
        lv_coord_t font_h = lv_font_get_line_height(font);

        lv_area_t roller_coords;
        lv_obj_get_coords(obj, &roller_coords);

        lv_area_t rect_area;
        rect_area.x1 = roller_coords.x1;
        rect_area.x2 = roller_coords.x2;
        rect_area.y1 = roller_coords.y1;
        rect_area.y2 = roller_coords.y1 + (lv_obj_get_height(obj) - font_h - line_space) / 2;

        lv_draw_mask_fade_param_t * fade_mask_top = lv_mem_buf_get(sizeof(lv_draw_mask_fade_param_t));
        lv_draw_mask_fade_init(fade_mask_top, &rect_area, LV_OPA_TRANSP, rect_area.y1, LV_OPA_COVER, rect_area.y2);
        mask_top_id = lv_draw_mask_add(fade_mask_top, NULL);

        rect_area.y1 = rect_area.y2 + font_h + line_space - 1;
        rect_area.y2 = roller_coords.y2;

        lv_draw_mask_fade_param_t * fade_mask_bottom = lv_mem_buf_get(sizeof(lv_draw_mask_fade_param_t));
        lv_draw_mask_fade_init(fade_mask_bottom, &rect_area, LV_OPA_COVER, rect_area.y1, LV_OPA_TRANSP, rect_area.y2);
        mask_bottom_id = lv_draw_mask_add(fade_mask_bottom, NULL);

    }
    else if(code == LV_EVENT_DRAW_POST_END) {
        lv_draw_mask_fade_param_t * fade_mask_top = lv_draw_mask_remove_id(mask_top_id);
        lv_draw_mask_fade_param_t * fade_mask_bottom = lv_draw_mask_remove_id(mask_bottom_id);
        lv_draw_mask_free_param(fade_mask_top);
        lv_draw_mask_free_param(fade_mask_bottom);
        lv_mem_buf_release(fade_mask_top);
        lv_mem_buf_release(fade_mask_bottom);
        mask_top_id = -1;
        mask_bottom_id = -1;
    }
}


static void mask_event_cb2(lv_event_t * e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t * obj = lv_event_get_target(e);

    static int16_t mask_top_id = -1;
    static int16_t mask_bottom_id = -1;

    if(code == LV_EVENT_VALUE_CHANGED) {
        char buf[32];
        lv_roller_get_selected_str(obj, buf, sizeof(buf));
        uint16_t index = lv_roller_get_selected(obj);
        LV_LOG_USER("Selected prov: %s, cnt: %d\n", buf, index);
    }
    else if(code == LV_EVENT_COVER_CHECK) {
        lv_event_set_cover_res(e, LV_COVER_RES_MASKED);
    }
    else if(code == LV_EVENT_DRAW_MAIN_BEGIN) {
        /* add mask */
        const lv_font_t * font = lv_obj_get_style_text_font(obj, LV_PART_MAIN);
        lv_coord_t line_space = lv_obj_get_style_text_line_space(obj, LV_PART_MAIN);
        lv_coord_t font_h = lv_font_get_line_height(font);

        lv_area_t roller_coords;
        lv_obj_get_coords(obj, &roller_coords);

        lv_area_t rect_area;
        rect_area.x1 = roller_coords.x1;
        rect_area.x2 = roller_coords.x2;
        rect_area.y1 = roller_coords.y1;
        rect_area.y2 = roller_coords.y1 + (lv_obj_get_height(obj) - font_h - line_space) / 2;

        lv_draw_mask_fade_param_t * fade_mask_top = lv_mem_buf_get(sizeof(lv_draw_mask_fade_param_t));
        lv_draw_mask_fade_init(fade_mask_top, &rect_area, LV_OPA_TRANSP, rect_area.y1, LV_OPA_COVER, rect_area.y2);
        mask_top_id = lv_draw_mask_add(fade_mask_top, NULL);

        rect_area.y1 = rect_area.y2 + font_h + line_space - 1;
        rect_area.y2 = roller_coords.y2;

        lv_draw_mask_fade_param_t * fade_mask_bottom = lv_mem_buf_get(sizeof(lv_draw_mask_fade_param_t));
        lv_draw_mask_fade_init(fade_mask_bottom, &rect_area, LV_OPA_COVER, rect_area.y1, LV_OPA_TRANSP, rect_area.y2);
        mask_bottom_id = lv_draw_mask_add(fade_mask_bottom, NULL);

    }
    else if(code == LV_EVENT_DRAW_POST_END) {
        lv_draw_mask_fade_param_t * fade_mask_top = lv_draw_mask_remove_id(mask_top_id);
        lv_draw_mask_fade_param_t * fade_mask_bottom = lv_draw_mask_remove_id(mask_bottom_id);
        lv_draw_mask_free_param(fade_mask_top);
        lv_draw_mask_free_param(fade_mask_bottom);
        lv_mem_buf_release(fade_mask_top);
        lv_mem_buf_release(fade_mask_bottom);
        mask_top_id = -1;
        mask_bottom_id = -1;
    }
}




/**
 * Add a fade mask to roller.
 */
void lv_example_roller_my(void)
{
    // static lv_style_t style;
    // lv_style_init(&style);
    // lv_style_set_bg_color(&style, lv_color_black());
    // lv_style_set_text_color(&style, lv_color_white());
    // lv_style_set_border_width(&style, 0);
    // lv_style_set_pad_all(&style, 0);
    // lv_obj_add_style(lv_scr_act(), &style, 0);

    lv_obj_t * roller1 = lv_roller_create(lv_scr_act());
    lv_obj_t * roller2 = lv_roller_create(lv_scr_act());
    // lv_obj_add_style(roller1, &style, 0);
    lv_obj_set_style_border_color(roller1, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT );
    lv_obj_set_style_bg_color(roller1, lv_color_hex(0xCBC9C9),   LV_STATE_DEFAULT | LV_PART_SELECTED);
    lv_obj_set_style_text_color(roller1, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT| LV_PART_SELECTED);
    lv_obj_set_style_bg_opa(roller1, LV_OPA_TRANSP, LV_PART_SELECTED);

    lv_obj_set_style_border_color(roller2, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT );
    lv_obj_set_style_bg_color(roller2, lv_color_hex(0xffffff),  LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(roller2, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT| LV_PART_SELECTED);
    lv_obj_set_style_bg_opa(roller2, LV_OPA_TRANSP, LV_PART_SELECTED);


    lv_obj_set_style_text_font(roller1, &HanSansCN_20, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(roller1, 0, LV_PART_MAIN | LV_STATE_DEFAULT );

    lv_obj_set_style_text_font(roller2, &HanSansCN_20, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(roller2, 0, LV_PART_MAIN | LV_STATE_DEFAULT );

    lv_roller_set_options(roller1,
                          test_pro_roller,
                          LV_ROLLER_MODE_NORMAL);
    lv_roller_set_options(roller2,
                        prov_list[0],
                        LV_ROLLER_MODE_NORMAL);

    lv_obj_set_pos(roller1, 140, 120);
    lv_obj_set_size(roller1, 120, 240);

    lv_obj_set_pos(roller2, 280, 120);
    lv_obj_set_size(roller2, 120, 240);
    // lv_obj_center(roller1);
    lv_roller_set_visible_row_count(roller1, 5);
    lv_roller_set_visible_row_count(roller2, 5);
    lv_obj_add_event_cb(roller1, mask_event_cb1, LV_EVENT_ALL, (void *)roller2);
    lv_obj_add_event_cb(roller2, mask_event_cb2, LV_EVENT_ALL, NULL);
}

#endif


int main(int argc, char **argv)
{
    (void)argc; /*Unused*/
    (void)argv; /*Unused*/

    /*Initialize LVGL*/
    lv_init();

    /*Initialize the HAL (display, input devices, tick) for LVGL*/
    hal_init();
    memset(&guider_ui, 0, sizeof(guider_ui));
    setup_ui(&guider_ui);
    // lv_example_win_1();
    // lv_example_roller_1();
    // lv_example_roller_3();
    // lv_example_roller_my();
    // ui_Screen1_screen_init();
    // lv_example_calendar_1();
    // lv_ex_imgbtn_1();
    //init_ui();
    // lv_demo_benchmark();
    // lv_demo_keypad_encoder();
    // lv_demo_stress();
    // lv_demo_widgets();
    //   lv_demo_music();
    // lv_example_anim_1();
    // lv_example_grid_my();
    // lv_example_btn_1();
    // lv_example_imgbtn_1();
    //    lv_example_slider_3();
    // lv_example_menu_5();
    //  lv_example_qrcode_1();
    //   lv_example_anim_2();
    // lv_example_img_3();
    // lv_example_keyboard_1();
    // lv_example_checkbox_1();
    // lv_example_msgbox_1();
    // lv_demo_stress();
    // lv_example_barcode_1();
    // d_ui_init();

    while (1) {
        /* Periodically call the lv_task handler.
         * It could be done in a timer interrupt or an OS task too.*/
        //lv_timer_handler();
        usleep(lv_timer_handler() * 1000);
    }

    return 0;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

/**
 * Initialize the Hardware Abstraction Layer (HAL) for the LVGL graphics
 * library
 */
static void hal_init(void)
{
    /* Use the 'monitor' driver which creates window on PC's monitor to simulate a display*/
    monitor_init();
    /* Tick init.
     * You have to call 'lv_tick_inc()' in periodically to inform LittelvGL about
     * how much time were elapsed Create an SDL thread to do this*/
    SDL_CreateThread(tick_thread, "tick", NULL);

    /*Create a display buffer*/
    static lv_disp_draw_buf_t disp_buf1;
    static lv_color_t buf1_1[MONITOR_HOR_RES * 100];
    static lv_color_t buf1_2[MONITOR_HOR_RES * 100];
    lv_disp_draw_buf_init(&disp_buf1, buf1_1, buf1_2, MONITOR_HOR_RES * 100);

    /*Create a display*/
    static lv_disp_drv_t disp_drv;
    lv_disp_drv_init(&disp_drv); /*Basic initialization*/
    disp_drv.draw_buf = &disp_buf1;
    disp_drv.flush_cb = monitor_flush;
    disp_drv.hor_res = MONITOR_HOR_RES;
    disp_drv.ver_res = MONITOR_VER_RES;
    disp_drv.antialiasing = 1;

    lv_disp_t *disp = lv_disp_drv_register(&disp_drv);

    lv_theme_t *th = lv_theme_default_init(disp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED), LV_THEME_DEFAULT_DARK, LV_FONT_DEFAULT);
    lv_disp_set_theme(disp, th);

    lv_group_t *g = lv_group_create();
    lv_group_set_default(g);

    /* Add the mouse as input device
     * Use the 'mouse' driver which reads the PC's mouse*/
    mouse_init();
    static lv_indev_drv_t indev_drv_1;
    lv_indev_drv_init(&indev_drv_1); /*Basic initialization*/
    indev_drv_1.type = LV_INDEV_TYPE_POINTER;

    /*This function will be called periodically (by the library) to get the mouse position and state*/
    indev_drv_1.read_cb = mouse_read;
    lv_indev_t *mouse_indev = lv_indev_drv_register(&indev_drv_1);

    keyboard_init();
    static lv_indev_drv_t indev_drv_2;
    lv_indev_drv_init(&indev_drv_2); /*Basic initialization*/
    indev_drv_2.type = LV_INDEV_TYPE_KEYPAD;
    indev_drv_2.read_cb = keyboard_read;
    lv_indev_t *kb_indev = lv_indev_drv_register(&indev_drv_2);
    lv_indev_set_group(kb_indev, g);
    mousewheel_init();
    static lv_indev_drv_t indev_drv_3;
    lv_indev_drv_init(&indev_drv_3); /*Basic initialization*/
    indev_drv_3.type = LV_INDEV_TYPE_ENCODER;
    indev_drv_3.read_cb = mousewheel_read;

    lv_indev_t *enc_indev = lv_indev_drv_register(&indev_drv_3);
    lv_indev_set_group(enc_indev, g);

    /*Set a cursor for the mouse*/
    LV_IMG_DECLARE(mouse_cursor_icon);                  /*Declare the image file.*/
    lv_obj_t *cursor_obj = lv_img_create(lv_scr_act()); /*Create an image object for the cursor */
    lv_img_set_src(cursor_obj, &mouse_cursor_icon);     /*Set the image source*/
    lv_indev_set_cursor(mouse_indev, cursor_obj);       /*Connect the image  object to the driver*/
}

/**
 * A task to measure the elapsed time for LVGL
 * @param data unused
 * @return never return
 */
static int tick_thread(void *data)
{
    (void)data;

    while (1) {
        SDL_Delay(5);
        lv_tick_inc(5); /*Tell LittelvGL that 5 milliseconds were elapsed*/
    }

    return 0;
}
