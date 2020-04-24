using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace 牛顿环计算
{
    /// <summary>
    /// MainWindow.xaml 的交互逻辑
    /// </summary>
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();
        }

        private void Button_Click(object sender, RoutedEventArgs e)
        {
            try
            {
                double[] l = new double[8];
                double[] r = new double[8];
                double[] D = new double[8];
                double[] squareDiff = new double[4];
                double sqDifAvg = 0, R = 0;
                string[] Data = data.Text.Split();
                for (int i = 0; i < 8; i++)
                {
                    l[i] = Convert.ToDouble(Data[i]) / 1e3;
                }
                for (int i = 0; i < 8; i++)
                {
                    r[i] = Convert.ToDouble(Data[i+8]) / 1e3;
                }
                for (int i = 0; i < 8; i++)
                {
                    D[i] = Math.Abs(r[i] - l[7-i]);
                }
                for (int i = 0; i < 4; i++)
                {
                    squareDiff[i] = D[i+4] * D[i+4] - D[i] * D[i];
                    sqDifAvg += squareDiff[i];
                }
                sqDifAvg /= 4;
                R = sqDifAvg / (80 * 589 * 1e-9);
                answer.Content = "R = " + string.Format("{0:.000}", R) + " m";
            }
            catch
            {
                answer.Content = "输入格式错误！";
            }
        }
        private void TextBox_TextChanged(object sender, TextChangedEventArgs e)
        {

        }
    }
}
