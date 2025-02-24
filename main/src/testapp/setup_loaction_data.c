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
 * @LastEditTime : 2024-03-06 16:16:01
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
} st_location;

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
#define xingjiang_roller "乌鲁木齐市\n克拉玛依市\n吐鲁番市\n哈密市\n昌吉回族自治州\n博尔塔拉蒙古自治州\n巴音郭楞蒙古自治州\n阿克苏地区\n克孜勒苏柯尔克孜自治州\n喀什地区\n和田地区\n伊犁哈萨克自治州\n塔城地区\n阿勒泰地区\n石河子市\n阿拉尔市\n阿拉尔市\n图木舒克市\n五家渠市"
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

// 邯郸朔忻汾鄂彦淖阜绥衢滁亳莆漳赣淄潍沂菏濮漯襄鄂邵郴韶圳汕湛肇莞儋泸遂羌孜洱彝傣迪傈喀渭峪陇柯喀吾


const local_city_t *cities0[]={
	&(local_city_t){"北京市","110100","116.395645","39.929986"},
};
const local_city_t *cities1[]={
	&(local_city_t){"天津市","120100","117.210813","39.14393"},
};
const local_city_t *cities2[]={
	&(local_city_t){"石家庄市","130100","114.522082","38.048958"},
	&(local_city_t){"唐山市","130200","118.183451","39.650531"},
	&(local_city_t){"秦皇岛市","130300","119.604368","39.945462"},
	&(local_city_t){"邯郸市","130400","114.482694","36.609308"},
	&(local_city_t){"邢台市","130500","114.520487","37.069531"},
	&(local_city_t){"保定市","130600","115.49481","38.886565"},
	&(local_city_t){"张家口市","130700","114.893782","40.811188"},
	&(local_city_t){"张家口市","130700","110.481622","29.124889"},
	&(local_city_t){"承德市","130800","117.933822","40.992521"},
	&(local_city_t){"沧州市","130900","116.863806","38.297615"},
	&(local_city_t){"廊坊市","131000","116.703602","39.518611"},
	&(local_city_t){"衡水市","131100","115.686229","37.746929"},
};
const local_city_t *cities3[]={
	&(local_city_t){"太原市","140100","112.550864","37.890277"},
	&(local_city_t){"大同市","140200","113.290509","40.113744"},
	&(local_city_t){"阳泉市","140300","113.569238","37.869529"},
	&(local_city_t){"长治市","140400","113.120292","36.201664"},
	&(local_city_t){"晋城市","140500","112.867333","35.499834"},
	&(local_city_t){"朔州市","140600","112.479928","39.337672"},
	&(local_city_t){"晋中市","140700","112.738514","37.693362"},
	&(local_city_t){"运城市","140800","111.006854","35.038859"},
	&(local_city_t){"忻州市","140900","112.727939","38.461031"},
	&(local_city_t){"临汾市","141000","111.538788","36.099745"},
	&(local_city_t){"吕梁市","141100","111.143157","37.527316"},
};
const local_city_t *cities4[]={
	&(local_city_t){"呼和浩特市","150100","111.660351","40.828319"},
	&(local_city_t){"包头市","150200","109.846239","40.647119"},
	&(local_city_t){"乌海市","150300","106.831999","39.683177"},
	&(local_city_t){"赤峰市","150400","118.930761","42.297112"},
	&(local_city_t){"通辽市","150500","122.260363","43.633756"},
	&(local_city_t){"鄂尔多斯市","150600","109.993706","39.81649"},
	&(local_city_t){"呼伦贝尔市","150700","119.760822","49.201636"},
	&(local_city_t){"巴彦淖尔市","150800","107.423807","40.76918"},
	&(local_city_t){"乌兰察布市","150900","113.112846","41.022363"},
	&(local_city_t){"兴安盟","152200","122.048167","46.083757"},
	&(local_city_t){"锡林郭勒盟","152500","116.02734","43.939705"},
	&(local_city_t){"阿拉善盟","152900","105.695683","38.843075"},
	&(local_city_t){"阿拉善盟","152900","81.2917373","40.615685"},
};
const local_city_t *cities5[]={
	&(local_city_t){"沈阳市","210100","123.432791","41.808645"},
	&(local_city_t){"大连市","210200","121.593478","38.94871"},
	&(local_city_t){"鞍山市","210300","123.007763","41.118744"},
	&(local_city_t){"抚顺市","210400","123.92982","41.877304"},
	&(local_city_t){"本溪市","210500","123.778062","41.325838"},
	&(local_city_t){"丹东市","210600","124.338543","40.129023"},
	&(local_city_t){"锦州市","210700","121.147749","41.130879"},
	&(local_city_t){"营口市","210800","122.233391","40.668651"},
	&(local_city_t){"阜新市","210900","121.660822","42.01925"},
	&(local_city_t){"辽阳市","211000","123.172451","41.273339"},
	&(local_city_t){"盘锦市","211100","122.073228","41.141248"},
	&(local_city_t){"铁岭市","211200","123.85485","42.299757"},
	&(local_city_t){"朝阳市","211300","120.446163","41.571828"},
	&(local_city_t){"葫芦岛市","211400","120.860758","40.74303"},
};
const local_city_t *cities6[]={
	&(local_city_t){"长春市","220100","125.313642","43.898338"},
	&(local_city_t){"吉林市","220200","126.262876","43.678846"},
	&(local_city_t){"四平市","220300","124.391382","43.175525"},
	&(local_city_t){"辽源市","220400","125.133686","42.923303"},
	&(local_city_t){"通化市","220500","125.94265","41.736397"},
	&(local_city_t){"白山市","220600","126.435798","41.945859"},
	&(local_city_t){"松原市","220700","124.832995","45.136049"},
	&(local_city_t){"白城市","220800","122.840777","45.621086"},
	&(local_city_t){"延边朝鲜族自治州","222400","129.485902","42.896414"},
};
const local_city_t *cities7[]={
	&(local_city_t){"哈尔滨市","230100","126.657717","45.773225"},
	&(local_city_t){"齐齐哈尔市","230200","123.987289","47.3477"},
	&(local_city_t){"鸡西市","230300","130.941767","45.32154"},
	&(local_city_t){"鹤岗市","230400","130.292472","47.338666"},
	&(local_city_t){"双鸭山市","230500","131.171402","46.655102"},
	&(local_city_t){"大庆市","230600","125.02184","46.596709"},
	&(local_city_t){"伊春市","230700","128.910766","47.734685"},
	&(local_city_t){"佳木斯市","230800","130.284735","46.81378"},
	&(local_city_t){"七台河市","230900","131.019048","45.775005"},
	&(local_city_t){"牡丹江市","231000","129.608035","44.588521"},
	&(local_city_t){"黑河市","231100","127.50083","50.25069"},
	&(local_city_t){"绥化市","231200","126.989095","46.646064"},
	&(local_city_t){"大兴安岭地区","232700","124.196104","51.991789"},
};
const local_city_t *cities8[]={
	&(local_city_t){"上海市","310100","121.487899","31.249162"},
};
const local_city_t *cities9[]={
	&(local_city_t){"南京市","320100","118.778074","32.057236"},
	&(local_city_t){"无锡市","320200","120.305456","31.570037"},
	&(local_city_t){"徐州市","320300","117.188107","34.271553"},
	&(local_city_t){"常州市","320400","119.981861","31.771397"},
	&(local_city_t){"苏州市","320500","120.619907","31.317987"},
	&(local_city_t){"南通市","320600","120.873801","32.014665"},
	&(local_city_t){"连云港市","320700","119.173872","34.601549"},
	&(local_city_t){"淮安市","320800","119.030186","33.606513"},
	&(local_city_t){"盐城市","320900","120.148872","33.379862"},
	&(local_city_t){"扬州市","321000","119.427778","32.408505"},
	&(local_city_t){"镇江市","321100","119.455835","32.204409"},
	&(local_city_t){"泰州市","321200","119.919606","32.476053"},
	&(local_city_t){"宿迁市","321300","118.296893","33.95205"},
};
const local_city_t *cities10[]={
	&(local_city_t){"杭州市","330100","120.219375","30.259244"},
	&(local_city_t){"宁波市","330200","121.579006","29.885259"},
	&(local_city_t){"温州市","330300","120.690635","28.002838"},
	&(local_city_t){"嘉兴市","330400","120.760428","30.773992"},
	&(local_city_t){"湖州市","330500","120.137243","30.877925"},
	&(local_city_t){"绍兴市","330600","120.592467","30.002365"},
	&(local_city_t){"金华市","330700","119.652576","29.102899"},
	&(local_city_t){"衢州市","330800","118.875842","28.95691"},
	&(local_city_t){"舟山市","330900","122.169872","30.03601"},
	&(local_city_t){"台州市","331000","121.440613","28.668283"},
	&(local_city_t){"丽水市","331100","119.929576","28.4563"},
};
const local_city_t *cities11[]={
	&(local_city_t){"合肥市","340100","117.282699","31.866942"},
	&(local_city_t){"芜湖市","340200","118.384108","31.36602"},
	&(local_city_t){"蚌埠市","340300","117.35708","32.929499"},
	&(local_city_t){"淮南市","340400","117.018639","32.642812"},
	&(local_city_t){"马鞍山市","340500","118.515882","31.688528"},
	&(local_city_t){"淮北市","340600","116.791447","33.960023"},
	&(local_city_t){"铜陵市","340700","117.819429","30.94093"},
	&(local_city_t){"安庆市","340800","117.058739","30.537898"},
	&(local_city_t){"黄山市","341000","118.29357","29.734435"},
	&(local_city_t){"滁州市","341100","118.32457","32.317351"},
	&(local_city_t){"阜阳市","341200","115.820932","32.901211"},
	&(local_city_t){"宿州市","341300","116.988692","33.636772"},
	&(local_city_t){"六安市","341500","116.505253","31.755558"},
	&(local_city_t){"亳州市","341600","115.787928","33.871211"},
	&(local_city_t){"池州市","341700","117.494477","30.660019"},
	&(local_city_t){"宣城市","341800","118.752096","30.951642"},
};
const local_city_t *cities12[]={
	&(local_city_t){"福州市","350100","119.330221","26.047125"},
	&(local_city_t){"厦门市","350200","118.103886","24.489231"},
	&(local_city_t){"莆田市","350300","119.077731","25.44845"},
	&(local_city_t){"三明市","350400","117.642194","26.270835"},
	&(local_city_t){"泉州市","350500","118.600362","24.901652"},
	&(local_city_t){"漳州市","350600","117.676205","24.517065"},
	&(local_city_t){"南平市","350700","118.181883","26.643626"},
	&(local_city_t){"龙岩市","350800","117.017997","25.078685"},
	&(local_city_t){"宁德市","350900","119.542082","26.656527"},
};
const local_city_t *cities13[]={
	&(local_city_t){"南昌市","360100","115.893528","28.689578"},
	&(local_city_t){"景德镇市","360200","117.186523","29.303563"},
	&(local_city_t){"萍乡市","360300","113.859917","27.639544"},
	&(local_city_t){"九江市","360400","115.999848","29.71964"},
	&(local_city_t){"新余市","360500","114.947117","27.822322"},
	&(local_city_t){"鹰潭市","360600","117.03545","28.24131"},
	&(local_city_t){"赣州市","360700","114.935909","25.845296"},
	&(local_city_t){"吉安市","360800","114.992039","27.113848"},
	&(local_city_t){"宜春市","360900","114.400039","27.81113"},
	&(local_city_t){"抚州市","361000","116.360919","27.954545"},
	&(local_city_t){"上饶市","361100","117.955464","28.457623"},
};
const local_city_t *cities14[]={
	&(local_city_t){"济南市","370100","117.024967","36.682785"},
	&(local_city_t){"青岛市","370200","120.384428","36.105215"},
	&(local_city_t){"淄博市","370300","118.059134","36.804685"},
	&(local_city_t){"枣庄市","370400","117.279305","34.807883"},
	&(local_city_t){"东营市","370500","118.583926","37.487121"},
	&(local_city_t){"烟台市","370600","121.309555","37.536562"},
	&(local_city_t){"潍坊市","370700","119.142634","36.716115"},
	&(local_city_t){"济宁市","370800","116.600798","35.402122"},
	&(local_city_t){"泰安市","370900","117.089415","36.188078"},
	&(local_city_t){"威海市","371000","122.093958","37.528787"},
	&(local_city_t){"日照市","371100","119.50718","35.420225"},
	&(local_city_t){"临沂市","371300","118.340768","35.072409"},
	&(local_city_t){"德州市","371400","116.328161","37.460826"},
	&(local_city_t){"聊城市","371500","115.986869","36.455829"},
	&(local_city_t){"滨州市","371600","117.968292","37.405314"},
	&(local_city_t){"菏泽市","371700","115.46336","35.26244"},
};
const local_city_t *cities15[]={
	&(local_city_t){"郑州市","410100","113.649644","34.75661"},
	&(local_city_t){"开封市","410200","114.351642","34.801854"},
	&(local_city_t){"洛阳市","410300","112.447525","34.657368"},
	&(local_city_t){"平顶山市","410400","113.300849","33.745301"},
	&(local_city_t){"安阳市","410500","114.351807","36.110267"},
	&(local_city_t){"鹤壁市","410600","114.29777","35.755426"},
	&(local_city_t){"新乡市","410700","113.91269","35.307258"},
	&(local_city_t){"焦作市","410800","113.211836","35.234608"},
	&(local_city_t){"濮阳市","410900","115.026627","35.753298"},
	&(local_city_t){"许昌市","411000","113.835312","34.02674"},
	&(local_city_t){"漯河市","411100","114.046061","33.576279"},
	&(local_city_t){"三门峡市","411200","111.181262","34.78332"},
	&(local_city_t){"南阳市","411300","112.542842","33.01142"},
	&(local_city_t){"商丘市","411400","115.641886","34.438589"},
	&(local_city_t){"信阳市","411500","114.085491","32.128582"},
	&(local_city_t){"周口市","411600","114.654102","33.623741"},
	&(local_city_t){"驻马店市","411700","114.049154","32.983158"},
};
const local_city_t *cities16[]={
	&(local_city_t){"武汉市","420100","114.3162","30.581084"},
	&(local_city_t){"黄石市","420200","115.050683","30.216127"},
	&(local_city_t){"十堰市","420300","110.801229","32.636994"},
	&(local_city_t){"宜昌市","420500","111.310981","30.732758"},
	&(local_city_t){"襄阳市","420600","112.176326","32.094934"},
	&(local_city_t){"鄂州市","420700","114.895594","30.384439"},
	&(local_city_t){"荆门市","420800","112.21733","31.042611"},
	&(local_city_t){"孝感市","420900","113.935734","30.927955"},
	&(local_city_t){"荆州市","421000","112.241866","30.332591"},
	&(local_city_t){"黄冈市","421100","114.906618","30.446109"},
	&(local_city_t){"咸宁市","421200","114.300061","29.880657"},
	&(local_city_t){"随州市","421300","113.379358","31.717858"},
	&(local_city_t){"恩施土家族苗族自治州","422800","109.517433","30.308978"},
	&(local_city_t){"仙桃市","429004","113.387448","30.293966"},
	&(local_city_t){"潜江市","429005","112.768768","30.343116"},
	&(local_city_t){"天门市","429006","113.12623","30.649047"},
	&(local_city_t){"神农架林区","429021","110.487231","31.595768"},
};
const local_city_t *cities17[]={
	&(local_city_t){"长沙市","430100","112.979353","28.213478"},
	&(local_city_t){"株洲市","430200","113.131695","27.827433"},
	&(local_city_t){"湘潭市","430300","112.935556","27.835095"},
	&(local_city_t){"衡阳市","430400","112.583819","26.898164"},
	&(local_city_t){"邵阳市","430500","111.461525","27.236811"},
	&(local_city_t){"岳阳市","430600","113.146196","29.378007"},
	&(local_city_t){"常德市","430700","111.653718","29.012149"},
	&(local_city_t){"张家界市","430800","114.893782","40.811188"},
	&(local_city_t){"张家界市","430800","110.481622","29.124889"},
	&(local_city_t){"益阳市","430900","112.366547","28.588088"},
	&(local_city_t){"郴州市","431000","113.037704","25.782264"},
	&(local_city_t){"永州市","431100","111.614648","26.435972"},
	&(local_city_t){"怀化市","431200","109.986959","27.557483"},
	&(local_city_t){"娄底市","431300","111.996396","27.741073"},
	&(local_city_t){"湘西土家族苗族自治州","433100","109.745746","28.317951"},
};
const local_city_t *cities18[]={
	&(local_city_t){"广州市","440100","113.30765","23.120049"},
	&(local_city_t){"韶关市","440200","113.594461","24.80296"},
	&(local_city_t){"深圳市","440300","114.025974","22.546054"},
	&(local_city_t){"珠海市","440400","113.562447","22.256915"},
	&(local_city_t){"汕头市","440500","116.72865","23.383908"},
	&(local_city_t){"佛山市","440600","113.134026","23.035095"},
	&(local_city_t){"江门市","440700","113.078125","22.575117"},
	&(local_city_t){"湛江市","440800","110.365067","21.257463"},
	&(local_city_t){"茂名市","440900","110.931245","21.668226"},
	&(local_city_t){"肇庆市","441200","112.479653","23.078663"},
	&(local_city_t){"惠州市","441300","114.410658","23.11354"},
	&(local_city_t){"梅州市","441400","116.126403","24.304571"},
	&(local_city_t){"汕尾市","441500","115.372924","22.778731"},
	&(local_city_t){"河源市","441600","114.713721","23.757251"},
	&(local_city_t){"阳江市","441700","111.97701","21.871517"},
	&(local_city_t){"清远市","441800","113.040773","23.698469"},
	&(local_city_t){"东莞市","441900","113.763434","23.043024"},
	&(local_city_t){"中山市","442000","113.42206","22.545178"},
	&(local_city_t){"潮州市","445100","116.630076","23.661812"},
	&(local_city_t){"揭阳市","445200","116.379501","23.547999"},
	&(local_city_t){"云浮市","445300","112.050946","22.937976"},
};
const local_city_t *cities19[]={
	&(local_city_t){"南宁市","450100","108.297234","22.806493"},
	&(local_city_t){"柳州市","450200","109.422402","24.329053"},
	&(local_city_t){"桂林市","450300","110.26092","25.262901"},
	&(local_city_t){"梧州市","450400","111.305472","23.485395"},
	&(local_city_t){"北海市","450500","109.122628","21.472718"},
	&(local_city_t){"防城港市","450600","108.351791","21.617398"},
	&(local_city_t){"钦州市","450700","108.638798","21.97335"},
	&(local_city_t){"贵港市","450800","109.613708","23.103373"},
	&(local_city_t){"玉林市","450900","110.151676","22.643974"},
	&(local_city_t){"百色市","451000","106.631821","23.901512"},
	&(local_city_t){"贺州市","451100","111.552594","24.411054"},
	&(local_city_t){"河池市","451200","108.069948","24.699521"},
	&(local_city_t){"来宾市","451300","109.231817","23.741166"},
	&(local_city_t){"崇左市","451400","107.357322","22.415455"},
};
const local_city_t *cities20[]={
	&(local_city_t){"海口市","460100","110.330802","20.022071"},
	&(local_city_t){"三亚市","460200","109.522771","18.257776"},
	&(local_city_t){"儋州市","460400","109.413973","19.571153"},
	&(local_city_t){"五指山市","469001","109.51775","18.831306"},
	&(local_city_t){"琼海市","469002","110.414359","19.21483"},
	&(local_city_t){"文昌市","469005","110.780909","19.750947"},
	&(local_city_t){"万宁市","469006","110.292505","18.839886"},
	&(local_city_t){"东方市","469007","108.85101","18.998161"},
	&(local_city_t){"定安县","469021","110.32009","19.490991"},
	&(local_city_t){"屯昌县","469022","110.063364","19.347749"},
	&(local_city_t){"澄迈县","469023","109.996736","19.693135"},
	&(local_city_t){"临高县","469024","109.724101","19.805922"},
	&(local_city_t){"白沙黎族自治县","469025","109.358586","19.216056"},
	&(local_city_t){"昌江黎族自治县","469026","109.0113","19.222483"},
	&(local_city_t){"乐东黎族自治县","469027","109.062698","18.658614"},
	&(local_city_t){"陵水黎族自治县","469028","109.948661","18.575985"},
	&(local_city_t){"保亭黎族苗族自治县","469029","109.656113","18.597592"},
	&(local_city_t){"琼中黎族苗族自治县","469030","109.861849","19.039771"},
};
const local_city_t *cities21[]={
	&(local_city_t){"重庆市","500100","106.530635","29.544606"},
};
const local_city_t *cities22[]={
	&(local_city_t){"成都市","510100","104.067923","30.679943"},
	&(local_city_t){"自贡市","510300","104.776071","29.359157"},
	&(local_city_t){"攀枝花市","510400","101.722423","26.587571"},
	&(local_city_t){"泸州市","510500","105.44397","28.89593"},
	&(local_city_t){"德阳市","510600","104.402398","31.13114"},
	&(local_city_t){"绵阳市","510700","104.705519","31.504701"},
	&(local_city_t){"广元市","510800","105.819687","32.44104"},
	&(local_city_t){"遂宁市","510900","105.564888","30.557491"},
	&(local_city_t){"内江市","511000","105.073056","29.599462"},
	&(local_city_t){"乐山市","511100","103.760824","29.600958"},
	&(local_city_t){"南充市","511300","106.105554","30.800965"},
	&(local_city_t){"眉山市","511400","103.84143","30.061115"},
	&(local_city_t){"宜宾市","511500","104.633019","28.769675"},
	&(local_city_t){"广安市","511600","106.63572","30.463984"},
	&(local_city_t){"达州市","511700","107.494973","31.214199"},
	&(local_city_t){"雅安市","511800","103.009356","29.999716"},
	&(local_city_t){"巴中市","511900","106.757916","31.869189"},
	&(local_city_t){"资阳市","512000","104.63593","30.132191"},
	&(local_city_t){"阿坝藏族羌族自治州","513200","102.228565","31.905763"},
	&(local_city_t){"甘孜藏族自治州","513300","101.969232","30.055144"},
	&(local_city_t){"凉山彝族自治州","513400","102.259591","27.892393"},
};
const local_city_t *cities23[]={
	&(local_city_t){"贵阳市","520100","106.709177","26.629907"},
	&(local_city_t){"六盘水市","520200","104.852087","26.591866"},
	&(local_city_t){"遵义市","520300","106.93126","27.699961"},
	&(local_city_t){"安顺市","520400","105.92827","26.228595"},
	&(local_city_t){"毕节市","520500","105.300492","27.302612"},
	&(local_city_t){"铜仁市","520600","109.196161","27.726271"},
	&(local_city_t){"黔西南布依族苗族自治州","522300","104.900558","25.095148"},
	&(local_city_t){"黔东南苗族侗族自治州","522600","107.985353","26.583992"},
	&(local_city_t){"黔南布依族苗族自治州","522700","107.523205","26.264536"},
};
const local_city_t *cities24[]={
	&(local_city_t){"昆明市","530100","102.714601","25.049153"},
	&(local_city_t){"曲靖市","530300","103.782539","25.520758"},
	&(local_city_t){"玉溪市","530400","102.545068","24.370447"},
	&(local_city_t){"保山市","530500","99.177996","25.120489"},
	&(local_city_t){"昭通市","530600","103.725021","27.340633"},
	&(local_city_t){"丽江市","530700","100.229628","26.875351"},
	&(local_city_t){"普洱市","530800","100.980058","22.788778"},
	&(local_city_t){"临沧市","530900","100.092613","23.887806"},
	&(local_city_t){"楚雄彝族自治州","532300","101.529382","25.066356"},
	&(local_city_t){"红河哈尼族彝族自治州","532500","103.384065","23.367718"},
	&(local_city_t){"文山壮族苗族自治州","532600","104.089112","23.401781"},
	&(local_city_t){"西双版纳傣族自治州","532800","100.803038","22.009433"},
	&(local_city_t){"大理白族自治州","532900","100.223675","25.5969"},
	&(local_city_t){"德宏傣族景颇族自治州","533100","98.589434","24.44124"},
	&(local_city_t){"怒江傈僳族自治州","533300","98.859932","25.860677"},
	&(local_city_t){"迪庆藏族自治州","533400","99.713682","27.831029"},
};
const local_city_t *cities25[]={
	&(local_city_t){"拉萨市","540100","91.111891","29.662557"},
	&(local_city_t){"日喀则市","540200","88.891486","29.269023"},
	&(local_city_t){"昌都市","540300","97.185582","31.140576"},
	&(local_city_t){"林芝市","540400","94.349985","29.666941"},
	&(local_city_t){"山南市","540500","91.750644","29.229027"},
	&(local_city_t){"那曲市","540600","92.067018","31.48068"},
	&(local_city_t){"阿里地区","542500","81.107669","30.404557"},
};
const local_city_t *cities26[]={
	&(local_city_t){"西安市","610100","108.953098","34.2778"},
	&(local_city_t){"铜川市","610200","108.968067","34.908368"},
	&(local_city_t){"宝鸡市","610300","107.170645","34.364081"},
	&(local_city_t){"咸阳市","610400","108.707509","34.345373"},
	&(local_city_t){"渭南市","610500","109.483933","34.502358"},
	&(local_city_t){"延安市","610600","109.50051","36.60332"},
	&(local_city_t){"汉中市","610700","107.045478","33.081569"},
	&(local_city_t){"榆林市","610800","109.745926","38.279439"},
	&(local_city_t){"安康市","610900","109.038045","32.70437"},
	&(local_city_t){"商洛市","611000","109.934208","33.873907"},
};
const local_city_t *cities27[]={
	&(local_city_t){"兰州市","620100","103.823305","36.064226"},
	&(local_city_t){"嘉峪关市","620200","98.281635","39.802397"},
	&(local_city_t){"金昌市","620300","102.208126","38.516072"},
	&(local_city_t){"白银市","620400","104.171241","36.546682"},
	&(local_city_t){"天水市","620500","105.736932","34.584319"},
	&(local_city_t){"武威市","620600","102.640147","37.933172"},
	&(local_city_t){"张掖市","620700","100.459892","38.93932"},
	&(local_city_t){"平凉市","620800","106.688911","35.55011"},
	&(local_city_t){"酒泉市","620900","98.508415","39.741474"},
	&(local_city_t){"庆阳市","621000","107.644227","35.726801"},
	&(local_city_t){"定西市","621100","104.626638","35.586056"},
	&(local_city_t){"陇南市","621200","104.934573","33.39448"},
	&(local_city_t){"临夏回族自治州","622900","103.215249","35.598514"},
	&(local_city_t){"甘南藏族自治州","623000","102.917442","34.992211"},
};
const local_city_t *cities28[]={
	&(local_city_t){"西宁市","630100","101.767921","36.640739"},
	&(local_city_t){"海东市","630200","102.085207","36.51761"},
	&(local_city_t){"海北藏族自治州","632200","100.879802","36.960654"},
	&(local_city_t){"黄南藏族自治州","632300","102.0076","35.522852"},
	&(local_city_t){"海南藏族自治州","632500","109.733755","19.180501"},
	&(local_city_t){"海南藏族自治州","632500","100.624066","36.284364"},
	&(local_city_t){"果洛藏族自治州","632600","100.223723","34.480485"},
	&(local_city_t){"玉树藏族自治州","632700","97.013316","33.00624"},
	&(local_city_t){"海西蒙古族藏族自治州","632800","97.342625","37.373799"},
};
const local_city_t *cities29[]={
	&(local_city_t){"银川市","640100","106.206479","38.502621"},
	&(local_city_t){"石嘴山市","640200","106.379337","39.020223"},
	&(local_city_t){"吴忠市","640300","106.208254","37.993561"},
	&(local_city_t){"固原市","640400","106.285268","36.021523"},
	&(local_city_t){"中卫市","640500","105.196754","37.521124"},
};
const local_city_t *cities30[]={
	&(local_city_t){"乌鲁木齐市","650100","87.564988","43.84038"},
	&(local_city_t){"克拉玛依市","650200","84.88118","45.594331"},
	&(local_city_t){"吐鲁番市","650400","89.181595","42.96047"},
	&(local_city_t){"哈密市","650500","93.528355","42.858596"},
	&(local_city_t){"昌吉回族自治州","652300","87.296038","44.007058"},
	&(local_city_t){"博尔塔拉蒙古自治州","652700","82.052436","44.913651"},
	&(local_city_t){"巴音郭楞蒙古自治州","652800","86.121688","41.771362"},
	&(local_city_t){"阿克苏地区","652900","80.269846","41.171731"},
	&(local_city_t){"克孜勒苏柯尔克孜自治州","653000","76.137564","39.750346"},
	&(local_city_t){"喀什地区","653100","75.992973","39.470627"},
	&(local_city_t){"和田地区","653200","79.930239","37.116774"},
	&(local_city_t){"伊犁哈萨克自治州","654000","81.297854","43.922248"},
	&(local_city_t){"塔城地区","654200","82.974881","46.758684"},
	&(local_city_t){"阿勒泰地区","654300","88.137915","47.839744"},
	&(local_city_t){"石河子市","659001","86.041865","44.308259"},
	&(local_city_t){"阿拉尔市","659002","105.695683","38.843075"},
	&(local_city_t){"阿拉尔市","659002","81.2917373","40.615685"},
	&(local_city_t){"图木舒克市","659003","79.198155","39.889223"},
	&(local_city_t){"五家渠市","659004","87.565449","44.368899"},
};
const local_city_t *cities31[]={
	&(local_city_t){"台北市","710100","121.5598","25.09108"},
	&(local_city_t){"高雄市","710200","120.666","23.01087"},
	&(local_city_t){"新北市","710300","121.6739","24.91571"},
	&(local_city_t){"台中市","710400","120.9417","24.23321"},
	&(local_city_t){"台南市","710500","120.2513","23.1417"},
	&(local_city_t){"桃园市","710600","121.2168","24.93759"},
	&(local_city_t){"基隆市","719001","121.7081","25.10898"},
	&(local_city_t){"新竹市","719002","120.9647","24.80395"},
	&(local_city_t){"嘉义市","719003","120.4473","23.47545"},
	&(local_city_t){"新竹县","719004","120.9647","24.80395"},
	&(local_city_t){"宜兰县","719005","121.7195","24.69295"},
	&(local_city_t){"苗栗县","719006","120.9417","24.48927"},
	&(local_city_t){"彰化县","719007","120.4818","23.99297"},
	&(local_city_t){"云林县","719008","120.3897","23.75585"},
	&(local_city_t){"南投县","719009","120.9876","23.83876"},
	&(local_city_t){"嘉义县","719010","120.4473","23.47545"},
	&(local_city_t){"屏东县","719011","120.62","22.54951"},
	&(local_city_t){"台东县","719012","120.9876","22.98461"},
	&(local_city_t){"花莲县","719013","121.3542","23.7569"},
	&(local_city_t){"澎湖县","719014","119.6151","23.56548"},
};
const local_city_t *cities32[]={
	&(local_city_t){"香港特别行政区","810000","114.186124","22.293586"},
};
const local_city_t *cities33[]={
	&(local_city_t){"澳门特别行政区","820000","113.557519","22.204118"},
};
st_location *all_location_data[]={
	&(st_location){"北京市",(local_city_t **)cities0},
	&(st_location){"天津市",(local_city_t **)cities1},
	&(st_location){"河北省",(local_city_t **)cities2},
	&(st_location){"山西省",(local_city_t **)cities3},
	&(st_location){"内蒙古自治区",(local_city_t **)cities4},
	&(st_location){"辽宁省",(local_city_t **)cities5},
	&(st_location){"吉林省",(local_city_t **)cities6},
	&(st_location){"黑龙江省",(local_city_t **)cities7},
	&(st_location){"上海市",(local_city_t **)cities8},
	&(st_location){"江苏省",(local_city_t **)cities9},
	&(st_location){"浙江省",(local_city_t **)cities10},
	&(st_location){"安徽省",(local_city_t **)cities11},
	&(st_location){"福建省",(local_city_t **)cities12},
	&(st_location){"江西省",(local_city_t **)cities13},
	&(st_location){"山东省",(local_city_t **)cities14},
	&(st_location){"河南省",(local_city_t **)cities15},
	&(st_location){"湖北省",(local_city_t **)cities16},
	&(st_location){"湖南省",(local_city_t **)cities17},
	&(st_location){"广东省",(local_city_t **)cities18},
	&(st_location){"广西壮族自治区",(local_city_t **)cities19},
	&(st_location){"海南省",(local_city_t **)cities20},
	&(st_location){"重庆市",(local_city_t **)cities21},
	&(st_location){"四川省",(local_city_t **)cities22},
	&(st_location){"贵州省",(local_city_t **)cities23},
	&(st_location){"云南省",(local_city_t **)cities24},
	&(st_location){"西藏自治区",(local_city_t **)cities25},
	&(st_location){"陕西省",(local_city_t **)cities26},
	&(st_location){"甘肃省",(local_city_t **)cities27},
	&(st_location){"青海省",(local_city_t **)cities28},
	&(st_location){"宁夏回族自治区",(local_city_t **)cities29},
	&(st_location){"新疆维吾尔自治区",(local_city_t **)cities30},
	&(st_location){"台湾省",(local_city_t **)cities31},
	&(st_location){"香港特别行政区",(local_city_t **)cities32},
	&(st_location){"澳门特别行政区",(local_city_t **)cities33},
};