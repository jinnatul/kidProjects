using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Calculator
{
    public partial class Form1 : Form
    {
        Double resultValue = 0.0;
        String oprtation = "";
        bool isoperation = false;

        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void button_Click(object sender, EventArgs e)
        {
            if ((textBoxResult.Text == "0") || isoperation )
                textBoxResult.Clear();

            isoperation = false;
            Button button = (Button)sender;

            if(button.Text == ".")
            {
                if(!textBoxResult.Text.Contains("."))
                    textBoxResult.Text = textBoxResult.Text + button.Text;
            }
            else
                textBoxResult.Text = textBoxResult.Text + button.Text;
        }

        private void operator_Click(object sender, EventArgs e)
        {
            Button button = (Button)sender;

            if (resultValue != 0)
            {
                buttonEQUAL.PerformClick();
                oprtation = button.Text;
                showInfo.Text = resultValue + " " + oprtation;
                isoperation = true;
              
            }
            else
            {
                oprtation = button.Text;
                resultValue = Double.Parse(textBoxResult.Text);
                showInfo.Text = resultValue + " " + oprtation;
                isoperation = true;
            }
        }

        private void buttonCE(object sender, EventArgs e)
        {
            textBoxResult.Text = "0";
        }

        private void buttonC(object sender, EventArgs e)
        {
            textBoxResult.Text = "0";
            resultValue = 0;
        }

        private void buttonCalculation(object sender, EventArgs e)
        {
            switch (oprtation)
            {
                case "+":
                    textBoxResult.Text = (resultValue + Double.Parse(textBoxResult.Text)).ToString();
                    break;

                case "-":
                    textBoxResult.Text = (resultValue - Double.Parse(textBoxResult.Text)).ToString();
                    break;

                case "*":
                    textBoxResult.Text = (resultValue * Double.Parse(textBoxResult.Text)).ToString();
                    break;

                case "/":
                    textBoxResult.Text = (resultValue / Double.Parse(textBoxResult.Text)).ToString();
                    break;
                default:
                    break;
            }

            resultValue = Double.Parse(textBoxResult.Text);
           // showInfo.Text = "";
        }
    }
}