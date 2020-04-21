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
    public partial class Book : System.Web.UI.Page
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
                SqlDataAdapter sqlDa = new SqlDataAdapter("SELECT * FROM Book", sqlCon);
                sqlDa.Fill(dtbl);

                SqlCommand sqlCmd = new SqlCommand("select avg (CAST(B_Price AS INT)) from Book", sqlCon);
                var result = sqlCmd.ExecuteScalar();
                lblSuccessMessage.Text = "Average Book Price : " + result.ToString();
            }
            if (dtbl.Rows.Count > 0)
            {
                gvBook.DataSource = dtbl;
                gvBook.DataBind();
            }
            else
            {
                dtbl.Rows.Add(dtbl.NewRow());
                gvBook.DataSource = dtbl;
                gvBook.DataBind();
                gvBook.Rows[0].Cells.Clear();
                gvBook.Rows[0].Cells.Add(new TableCell());
                gvBook.Rows[0].Cells[0].ColumnSpan = dtbl.Columns.Count;
                gvBook.Rows[0].Cells[0].Text = "No Data Found ..!";
                gvBook.Rows[0].Cells[0].HorizontalAlign = HorizontalAlign.Center;
            }

        }


        protected void gvBook_RowCommand(object sender, GridViewCommandEventArgs e)
        {
            try
            {
                if (e.CommandName.Equals("AddNew"))
                {
                    using (SqlConnection sqlCon = new SqlConnection(dbconStr))
                    {
                        sqlCon.Open();
                        //string query = "INSERT INTO Book (B_Title,B_Author) VALUES (@B_Title,@B_Author)";
                        //SqlCommand sqlCmd = new SqlCommand(query, sqlCon);

                        SqlCommand sqlCmd = new SqlCommand("book_Insert", sqlCon);
                        sqlCmd.CommandType = CommandType.StoredProcedure;

                        sqlCmd.Parameters.AddWithValue("@B_Title", (gvBook.FooterRow.FindControl("txtB_TitleFooter") as TextBox).Text.Trim());
                        sqlCmd.Parameters.AddWithValue("@B_Author", (gvBook.FooterRow.FindControl("txtB_AuthorFooter") as TextBox).Text.Trim());
                        sqlCmd.Parameters.AddWithValue("@B_Price", (gvBook.FooterRow.FindControl("txtB_PriceFooter") as TextBox).Text.Trim());
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

        protected void gvBook_RowEditing(object sender, GridViewEditEventArgs e)
        {
            gvBook.EditIndex = e.NewEditIndex;
            PopulateGridview();
        }

        protected void gvBook_RowCancelingEdit(object sender, GridViewCancelEditEventArgs e)
        {
            gvBook.EditIndex = -1;
            PopulateGridview();
        }

        protected void gvBook_RowUpdating(object sender, GridViewUpdateEventArgs e)
        {
            try
            {
                using (SqlConnection sqlCon = new SqlConnection(dbconStr))
                {
                    sqlCon.Open();
                    string query = "UPDATE Book SET B_Title=@B_Title,B_Author=@B_Author,B_Price=@B_Price WHERE B_Id = @B_Id";
                    SqlCommand sqlCmd = new SqlCommand(query, sqlCon);

                    sqlCmd.Parameters.AddWithValue("@B_Title", (gvBook.Rows[e.RowIndex].FindControl("txtB_Title") as TextBox).Text.Trim());
                    sqlCmd.Parameters.AddWithValue("@B_Author", (gvBook.Rows[e.RowIndex].FindControl("txtB_Author") as TextBox).Text.Trim());
                    sqlCmd.Parameters.AddWithValue("@B_Price", (gvBook.Rows[e.RowIndex].FindControl("txtB_Price") as TextBox).Text.Trim());
                    sqlCmd.Parameters.AddWithValue("@B_Id", Convert.ToInt32(gvBook.DataKeys[e.RowIndex].Value.ToString()));
                    sqlCmd.ExecuteNonQuery();
                    gvBook.EditIndex = -1;
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

        protected void gvBook_RowDeleting(object sender, GridViewDeleteEventArgs e)
        {
            try
            {
                using (SqlConnection sqlCon = new SqlConnection(dbconStr))
                {
                    sqlCon.Open();
                    string query = "DELETE FROM Book WHERE B_Id = @B_Id";
                    SqlCommand sqlCmd = new SqlCommand(query, sqlCon);
                    sqlCmd.Parameters.AddWithValue("@B_Id", Convert.ToInt32(gvBook.DataKeys[e.RowIndex].Value.ToString()));
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