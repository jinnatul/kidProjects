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
    public partial class Student : System.Web.UI.Page
    {
        string dbconStr = WebConfigurationManager.ConnectionStrings["dbconnection"].ConnectionString;
        protected void Page_Load(object sender, EventArgs e)
        {
            if (!IsPostBack)
            {
                PopulateGridview();
            }
        }

        void PopulateGridview()
        {
            DataTable dtbl = new DataTable();
            using (SqlConnection sqlCon = new SqlConnection(dbconStr))
            {
                sqlCon.Open();
                SqlDataAdapter sqlDa = new SqlDataAdapter("SELECT * FROM Student", sqlCon);
                sqlDa.Fill(dtbl);
            }
            if (dtbl.Rows.Count > 0)
            {
                gvStudent.DataSource = dtbl;
                gvStudent.DataBind();
            }
            else
            {
                dtbl.Rows.Add(dtbl.NewRow());
                gvStudent.DataSource = dtbl;
                gvStudent.DataBind();
                gvStudent.Rows[0].Cells.Clear();
                gvStudent.Rows[0].Cells.Add(new TableCell());
                gvStudent.Rows[0].Cells[0].ColumnSpan = dtbl.Columns.Count;
                gvStudent.Rows[0].Cells[0].Text = "No Data Found ..!";
                gvStudent.Rows[0].Cells[0].HorizontalAlign = HorizontalAlign.Center;
            }

        }

        protected void gvStudent_RowCommand(object sender, GridViewCommandEventArgs e)
        {
            try
            {
                if (e.CommandName.Equals("AddNew"))
                {
                    using (SqlConnection sqlCon = new SqlConnection(dbconStr))
                    {
                        sqlCon.Open();
                        string query = "INSERT INTO Student (SV_Id,S_Name,S_Division) VALUES (@SV_Id,@S_Name,@S_Division)";
                        SqlCommand sqlCmd = new SqlCommand(query, sqlCon);
                        sqlCmd.Parameters.AddWithValue("@SV_Id", (gvStudent.FooterRow.FindControl("txtSV_IdFooter") as TextBox).Text.Trim());
                        sqlCmd.Parameters.AddWithValue("@S_Name", (gvStudent.FooterRow.FindControl("txtS_NameFooter") as TextBox).Text.Trim());
                        sqlCmd.Parameters.AddWithValue("@S_Division", (gvStudent.FooterRow.FindControl("txtS_DivisionFooter") as TextBox).Text.Trim());
                        sqlCmd.ExecuteNonQuery();
                        PopulateGridview();
                        lblSuccessMessage.Text = "New Record Added";
                        lblErrorMessage.Text = "";
                    }
                }
            }
            catch (Exception ex)
            {
                lblSuccessMessage.Text = "";
                lblErrorMessage.Text = ex.Message;
            }
        }

        protected void gvStudent_RowEditing(object sender, GridViewEditEventArgs e)
        {
            gvStudent.EditIndex = e.NewEditIndex;
            PopulateGridview();
        }

        protected void gvStudent_RowCancelingEdit(object sender, GridViewCancelEditEventArgs e)
        {
            gvStudent.EditIndex = -1;
            PopulateGridview();
        }

        protected void gvStudent_RowUpdating(object sender, GridViewUpdateEventArgs e)
        {
            try
            {
                using (SqlConnection sqlCon = new SqlConnection(dbconStr))
                {
                    sqlCon.Open();
                    //string query = "UPDATE Student SET SV_Id=@SV_Id,S_Name=@S_Name,S_Division=@S_Division WHERE S_Id = @S_Id";
                    //SqlCommand sqlCmd = new SqlCommand(query, sqlCon);

                    SqlCommand sqlCmd = new SqlCommand("student_Update", sqlCon);
                    sqlCmd.CommandType = CommandType.StoredProcedure;

                    sqlCmd.Parameters.AddWithValue("@SV_Id", (gvStudent.Rows[e.RowIndex].FindControl("txtSV_Id") as TextBox).Text.Trim());
                    sqlCmd.Parameters.AddWithValue("@S_Name", (gvStudent.Rows[e.RowIndex].FindControl("txtS_Name") as TextBox).Text.Trim());
                    sqlCmd.Parameters.AddWithValue("@S_Division", (gvStudent.Rows[e.RowIndex].FindControl("txtS_Division") as TextBox).Text.Trim());
                    sqlCmd.Parameters.AddWithValue("@S_Id", Convert.ToInt32(gvStudent.DataKeys[e.RowIndex].Value.ToString()));
                    sqlCmd.ExecuteNonQuery();
                    gvStudent.EditIndex = -1;
                    PopulateGridview();
                    lblSuccessMessage.Text = "Selected Record Updated";
                    lblErrorMessage.Text = "";
                }
            }
            catch (Exception ex)
            {
                lblSuccessMessage.Text = "";
                lblErrorMessage.Text = ex.Message;
            }
        }

        protected void gvStudent_RowDeleting(object sender, GridViewDeleteEventArgs e)
        {
            try
            {
                using (SqlConnection sqlCon = new SqlConnection(dbconStr))
                {
                    sqlCon.Open();
                    string query = "DELETE FROM Student WHERE S_Id = @S_Id";
                    SqlCommand sqlCmd = new SqlCommand(query, sqlCon);
                    sqlCmd.Parameters.AddWithValue("@S_Id", Convert.ToInt32(gvStudent.DataKeys[e.RowIndex].Value.ToString()));
                    sqlCmd.ExecuteNonQuery();
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