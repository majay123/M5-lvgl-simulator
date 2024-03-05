/*
 * 
 * 　　┏┓　　　┏┓+ +
 * 　┏┛┻━━━┛┻┓ + +
 * 　┃　　　　　　　┃ 　
 * 　┃　　　━　　　┃ ++ + + +
 *  ████━████ ┃+
 * 　┃　　　　　　　┃ +
 * 　┃　　　┻　　　┃
 * 　┃　　　　　　　┃ + +
 * 　┗━┓　　　┏━┛
 * 　　　┃　　　┃　　　　　　　　　　　
 * 　　　┃　　　┃ + + + +
 * 　　　┃　　　┃
 * 　　　┃　　　┃ +  神兽保佑
 * 　　　┃　　　┃    代码无bug　　
 * 　　　┃　　　┃　　+　　　　　　　　　
 * 　　　┃　 　　┗━━━┓ + +
 * 　　　┃ 　　　　　　　┣┓
 * 　　　┃ 　　　　　　　┏┛
 * 　　　┗┓┓┏━┳┓┏┛ + + + +
 * 　　　　┃┫┫　┃┫┫
 * 　　　　┗┻┛　┗┻┛+ + + +
 * 
 * 
 * 
 * ************Copyright 2024 MCD************
 * 
 * @version      : 
 * @Company      : HOPE
 * @Author       : MCD
 * @Date         : 2024-03-04 14:06:05
 * @LastEditors  : MCD
 * @LastEditTime : 2024-03-05 13:21:39
 * @FilePath     : /M5-lvgl-simulator/main/src/testapp/setup_loaction_data.c
 * @Description  : 
 * 
 * ******************************************
 */

typedef struct {
    char *name;
    char *code;
    char *lat;
    char *lng;
} local_city_t;

typedef struct {
    char *prov;
    local_city_t **cities;
} st_loaction;

// const char *pro_roller = "北京市\n天津市\n河北省\n山西省\n内蒙古\n辽宁省\n吉林省\n黑龙江省\n上海市\n"
//                          "江苏省\n浙江省\n安徽省\n福建省\n江西省\n山东省\n河南省\n湖北省\n湖南省\n"
//                          "广东省\n广西\n海南省\n重庆市\n四川省\n贵州省\n云南省\n西藏\n陕西省\n甘肃省\n"
//                          "青海省\n宁夏\n新疆\n台湾省\n香港\n澳门";

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