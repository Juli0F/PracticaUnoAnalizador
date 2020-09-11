<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="LoadFile.aspx.cs" Inherits="Analizador_Lexico.Views.WebForm1" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title></title>
</head>
<body>
    <form id="Form1" method="post" runat="server" EncType="multipart/form-data" action="WebForm1.aspx">
        <div>
            <asp:FileUpload  ID = "FileText" runat = "server" />
            <br />
            
            <br /><br />
            <asp:Label ID="Label1" runat="server" Text=""></asp:Label>
            <asp:button id="btnUpload" type="submit" text="Upload" runat="server"></asp:button>
        </div>
    </form>
</body>
</html>
