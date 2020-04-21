<%@ Page Title="Home Page" Language="C#" MasterPageFile="~/Site.Master" AutoEventWireup="true" CodeBehind="Default.aspx.cs" Inherits="stor._Default" %>

<asp:Content ID="BodyContent" ContentPlaceHolderID="MainContent" runat="server">

        <div>

            <br /><br />
            <h3>Book Available Name</h3>
            <asp:DropDownList ID="DL_B_Title" DataTextField="B_Title" DataValueField="B_Id" runat="server"></asp:DropDownList>
            <br />

            <h3>Student Name</h3>
            <asp:DropDownList ID="DL_S_Name" DataTextField="S_Name" DataValueField="S_Id" runat="server"></asp:DropDownList>
            <br /><br />
            <asp:Button ID="btnPurchase" runat="server" Text="Button" OnClick="btnPurchase_Click" />
            <br /><br />
            
            <asp:GridView ID="gvPurchase" runat="server" AutoGenerateColumns="false" ShowFooter="true" DataKeyNames="P_Id"
                ShowHeaderWhenEmpty="true"

                OnRowDeleting="gvPurchase_RowDeleting"

                BackColor="White" BorderColor="#CCCCCC" BorderStyle="None" BorderWidth="1px" CellPadding="3">
               
                <%-- Theme Properties --%>
                <FooterStyle BackColor="White" ForeColor="#000066" />
                <HeaderStyle BackColor="#006699" Font-Bold="True" ForeColor="White" />
                <PagerStyle BackColor="White" ForeColor="#000066" HorizontalAlign="Left" />
                <RowStyle ForeColor="#000066" />
                <SelectedRowStyle BackColor="#669999" Font-Bold="True" ForeColor="White" />
                <SortedAscendingCellStyle BackColor="#F1F1F1" />
                <SortedAscendingHeaderStyle BackColor="#007DBB" />
                <SortedDescendingCellStyle BackColor="#CAC9C9" />
                <SortedDescendingHeaderStyle BackColor="#00547E" />
                
                <Columns>
                    
                    <asp:TemplateField HeaderText="Versity ID">
                        <ItemTemplate>
                            <asp:Label Text='<%# Eval("SV_Id") %>' runat="server" />
                        </ItemTemplate>
                    </asp:TemplateField>
                    
                    <asp:TemplateField HeaderText="Student_Name">
                        <ItemTemplate>
                            <asp:Label Text='<%# Eval("S_Name") %>' runat="server" />
                        </ItemTemplate>
                    </asp:TemplateField>

                    <asp:TemplateField HeaderText="Divison">
                        <ItemTemplate>
                            <asp:Label Text='<%# Eval("S_Division") %>' runat="server" />
                        </ItemTemplate>
                    </asp:TemplateField>

                    <asp:TemplateField HeaderText="Book_Title">
                        <ItemTemplate>
                            <asp:Label Text='<%# Eval("B_Title") %>' runat="server" />
                        </ItemTemplate>
                    </asp:TemplateField>

                    <asp:TemplateField HeaderText="Book_Author">
                        <ItemTemplate>
                            <asp:Label Text='<%# Eval("B_Author") %>' runat="server" />
                        </ItemTemplate>
                    </asp:TemplateField>

                    <asp:TemplateField HeaderText="Book_Price">
                        <ItemTemplate>
                            <asp:Label Text='<%# Eval("B_Price") %>' runat="server" />
                        </ItemTemplate>
                    </asp:TemplateField>

                    <asp:TemplateField HeaderText="Book_Price_Quality">
                        <ItemTemplate>
                            <asp:Label Text='<%# Eval("B_Quality") %>' runat="server" />
                        </ItemTemplate>
                    </asp:TemplateField>
                   
                    <asp:TemplateField>
                         <ItemTemplate>
                            <asp:ImageButton ImageUrl="~/Images/delete.png" runat="server" CommandName="Delete" ToolTip="Delete" Width="20px" Height="20px"/>
                        </ItemTemplate>
                    </asp:TemplateField>

                </Columns>

            </asp:GridView>
            <br />
            
            <asp:Label ID="lblSuccessMessage" Text="" runat="server" ForeColor="Green" />
            <br />
            <asp:Label ID="lblErrorMessage" Text="" runat="server" ForeColor="Red" />

        </div>

</asp:Content>
