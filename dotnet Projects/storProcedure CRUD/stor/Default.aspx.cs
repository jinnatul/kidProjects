using System;
using System.Collections.Generic;
using System.Data;
using System.Data.SqlClient;
using System.Linq;
using System.Web;
using System.Web.Configuration;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace stor
{
    public partial class _Default : Page
    {
        string dbconStr = WebConfigurationManager.ConnectionStrings["dbconnection"].ConnectionString;
        protected void Page_Load(object sender, EventArgs e)
        {
            if (!IsPostBack)
            {
                dropDownBook();
                dropDownStudent();
                deletePrice();
                PopulateGridview();
            }
        }

        void deletePrice()
        {
            using (SqlConnection sqlCon = new SqlConnection(dbconStr))
            {
                sqlCon.Open();
                SqlCommand cmd = new SqlCommand("setAvgPrice", sqlCon);
                cmd.Parameters.Add("@Price", SqlDbType.VarChar).Value = "100";
                cmd.CommandType = CommandType.StoredProcedure;
                cmd.ExecuteNonQuery();
            }
        }

        void dropDownBook()
        {
            DataTable dtbl = new DataTable();
            using (SqlConnection sqlCon = new SqlConnection(dbconStr))
            {
                sqlCon.Open();
                SqlCommand sqlDaBook = new SqlCommand("SELECT B_Id, B_Title FROM Book", sqlCon);
                DL_B_Title.DataSource = sqlDaBook.ExecuteReader();
                DL_B_Title.DataBind();
            }
        }

        void dropDownStudent()
        {
            DataTable dtbl = new DataTable();
            using (SqlConnection sqlCon = new SqlConnection(dbconStr))
            {
                sqlCon.Open();
                SqlCommand sqlDaStd = new SqlCommand("SELECT S_Id, S_Name FROM Student", sqlCon);
                DL_S_Name.DataSource = sqlDaStd.ExecuteReader();
                DL_S_Name.DataBind();
            }
        }

        void PopulateGridview()
        {
            DataTable dtbl = new DataTable();
            using (SqlConnection sqlCon = new SqlConnection(dbconStr))
            {
                sqlCon.Open();
                //SqlDataAdapter sqlDa = new SqlDataAdapter("SELECT * FROM ((Purchase INNER JOIN Book on Purchase.B_Id=Book.B_Id)INNER JOIN Student on Purchase.S_Id = Student.S_Id)", sqlCon);
                //sqlDa.Fill(dtbl);

                SqlCommand cmd = new SqlCommand();
                cmd.CommandType = CommandType.StoredProcedure;
                cmd.CommandText = "purchase_Select";
                cmd.Connection = sqlCon;

                try

                {
                    gvPurchase.EmptyDataText = "No Records Found";
                    gvPurchase.DataSource = cmd.ExecuteReader();
                    gvPurchase.DataBind();
                    //lblSuccessMessage.Text = 
                }

                catch (Exception ex)

                {
                    lblSuccessMessage.Text = "";
                    lblErrorMessage.Text = ex.Message;
                }
                finally
                {
                    sqlCon.Close();
                }
            }
            /*
            if (dtbl.Rows.Count > 0)
            {
                gvPurchase.DataSource = dtbl;
                gvPurchase.DataBind();
                lblSuccessMessage.Text = "ID 5";
            }
            else
            {
                dtbl.Rows.Add(dtbl.NewRow());
                gvPurchase.DataSource = dtbl;
                gvPurchase.DataBind();
                gvPurchase.Rows[0].Cells.Clear();
                gvPurchase.Rows[0].Cells.Add(new TableCell());
                gvPurchase.Rows[0].Cells[0].ColumnSpan = dtbl.Columns.Count;
                gvPurchase.Rows[0].Cells[0].Text = "No Data Found ..!";
                gvPurchase.Rows[0].Cells[0].HorizontalAlign = HorizontalAlign.Center;
            }
            */
        }

        protected void btnPurchase_Click(object sender, EventArgs e)
        {
            try
            {
                using (SqlConnection sqlCon = new SqlConnection(dbconStr))
                {
                    sqlCon.Open();
                    string query = "INSERT INTO Purchase (B_Id,S_Id) VALUES (@B_Id,@S_Id)";
                    SqlCommand sqlCmd = new SqlCommand(query, sqlCon);
                    sqlCmd.Parameters.AddWithValue("@B_Id", DL_B_Title.SelectedItem.Value);
                    sqlCmd.Parameters.AddWithValue("@S_Id", DL_S_Name.SelectedItem.Value);
                    int ok = sqlCmd.ExecuteNonQuery();
                    deletePrice();
                    PopulateGridview(); 
                    lblSuccessMessage.Text = "New Record Added";
                    lblErrorMessage.Text = "";
                }
            }
            catch (Exception ex)
            {
                lblSuccessMessage.Text = "";
                lblErrorMessage.Text = ex.Message;
            }
        }

        
        protected void gvPurchase_RowDeleting(object sender, GridViewDeleteEventArgs e)
        {
            try
            {
                using (SqlConnection sqlCon = new SqlConnection(dbconStr))
                {
                    sqlCon.Open();
                    string query = "DELETE FROM Purchase WHERE P_Id = @P_Id";
                    SqlCommand sqlCmd = new SqlCommand(query, sqlCon);
                    sqlCmd.Parameters.AddWithValue("@P_Id", Convert.ToInt32(gvPurchase.DataKeys[e.RowIndex].Value.ToString()));
                    sqlCmd.ExecuteNonQuery();
                    deletePrice();
                    PopulateGridview();
                    lblSuccessMessage.Text = "Selected Record Deleted";
                    lblErrorMessage.Text = "";
                }
            }
            catch (Exception ex)
            {
                lblSuccessMessage.Text = "";
                lblErrorMessage.Text = ex.Message;
            }
        }
    }
}