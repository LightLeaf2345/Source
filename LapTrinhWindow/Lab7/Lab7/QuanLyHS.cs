using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Lab7
{
    public partial class QUANLYHOCSINH : Form
    {
        public QUANLYHOCSINH()
        {
            InitializeComponent();
        }

        private void toolStripButton1_Click(object sender, EventArgs e)
        {

        }

        private void timer1_Tick(object sender, EventArgs e)
        {

        }

        private void InitializeComponent()
        {
            this.SuspendLayout();
            // 
            // QUANLYHOCSINH
            // 
            this.ClientSize = new System.Drawing.Size(282, 253);
            this.Name = "QUANLYHOCSINH";
            this.Load += new System.EventHandler(this.QUANLYHOCSINH_Load);
            this.ResumeLayout(false);

        }

        private void QUANLYHOCSINH_Load(object sender, EventArgs e)
        {
            private void LoginToolStripMenuItem_Click(object sender, System.EventArgs e)
            {
                loginForm = new LoginForm();
                loginForm.MdiParent = this;
                loginForm.Show();
                loginForm.Dock = DockStyle.Fill;
                loginForm.WindowState = FormWindowState.Maximized;
                this.LayoutMdi(MdiLayout.Cascade);
            }

            private void btnLogin_Click(object sender, System.EventArgs e)
            {
                string userName = txtUserName.Text;
                string password = txtPwd.Text;
                /*
                 * User user = studentManagementEntities
                 * User.FirstOrDefault(p => p.UserName
                 * var query = studentManagementEntities.User
                 * if (user != null)
                 */
                if (userName == null || password == null)
                {
                    MessageBox.Show("Login Successful");
                }
                else
                {
                    MessageBox.Show("Failed Login");
                }
            }
    }
}
