<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
	pageEncoding="ISO-8859-1"%>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core"%>
<%@ taglib uri="http://www.springframework.org/security/tags"
	prefix="security"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="ISO-8859-1">
<title>User page</title>
</head>
<body>
	<h1>${title}</h1>
	<h3>${message}</h3>
	<c:if test="${pageContext.request.userPrincipal.name != null}">
		<security:authorize access="hasRole('ROLE_USER')">
			<h4>
				Welcome : ${pageContext.request.userPrincipal.name} | <a
					href="<c:url value="/perform_logout" />">Logout</a>
			</h4>
		</security:authorize>
	</c:if>
</body>
</html>