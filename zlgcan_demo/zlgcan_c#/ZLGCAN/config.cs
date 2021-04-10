using System;

namespace ZLGCAN
{
    /**
     *  \struct Options
     * 节点mata的可选项。
     */
    public struct Options
    {
        /*! 可选项的数据类型*/
        public string type;

        /*! 可选项的值*/
        public string value;

        /*! 可选项的描述信息*/
        public string desc;
    };

    /**
     *  \struct Meta
     * 节点mata信息。
     */
    public struct Meta
    {
        /*! 配置项的数据类型 */
        public string type;

        /*! 配置项的说明性信息 */
        public string desc;

        /*! 配置项是否是只读的，缺省为可读写 */
        public int read_only;

        /*! 配置项输入格式的提示 */
        public string format;

        /*! 对于数值类型的配置项来说是最小值，对字符串的配置项来说是最小长度（字节数）。 */
        public double min_value;

        /*! 对于数值类型的配置项来说是最大值，对字符串的配置项来说是最大长度（字节数）。 */
        public double max_value;

        /*! 配置项的单位 */
        public string unit;

        /*! 通过旋钮/滚轮等方式修改配置项时的增量 */
        public double delta;

        /*! 配置项是否可见, true可见，false不可见，也可以绑定表达式（表达式使用参考demo3），缺省可见 */
        public string visible;

        /*! 该配置项是否使能, true使能，false不使能，也可以绑定表达式（表达式使用参考demo3）。缺省使能 */
        public string enable;

        /*! 配置项的可选值，仅但『type』为间接类型时有效 */
        public int editable;

        /*! 配置项的可选值，仅但『type』为间接类型时有效，以NULL结束 */
        //public Options** options;
        public IntPtr options;
    };

    /**
     *  \struct Pair
     *  属性的KeyValue对。
     */
    public struct Pair
    {
        public string key;
        public string value;
    };

    /**
     *  \struct ConfigNode 
     *  ConfigNode
     */
    public struct ConfigNode
    {
        /*! 节点的名字 */
        public string name;
        /*! 节点的值 同样可以绑定表达式*/
        public string value;
        /*! 节点值的表达式，当有该表达式时，value由此表达式计算而来*/
        public string binding_value;
        /*! 该节点的路径 */
        public string path;
        /*! 配置项信息 */
        //public Meta* meta_info;
        public IntPtr meta_info;
        /*! 该节点的子节点, 以NULL结束*/
        //public ConfigNode** children;
        public IntPtr children;
        /*! 该节点的属性, 以NULL结束*/
        //public Pair** attributes;
        public IntPtr attributes;
    };
}
