<%@taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core"%>
<%@ taglib uri="http://www.springframework.org/security/tags"
	prefix="security"%>
<%@page language="java" contentType="text/html; charset=ISO-8859-1" isELIgnored="false" pageEncoding="ISO-8859-1" session="true"%>
<html>
<body>
	<h1>${title}</h1>
	<h3>${message}</h3>

	<c:if test="${pageContext.request.userPrincipal.name != null}">
	<security:authorize access="hasRole('ROLE_ADMIN')">
		<h2>
			Welcome : ${pageContext.request.userPrincipal.name} | <a href="<c:url value="/perform_logout" />">Logout</a>
		</h2>
	</security:authorize>
	</c:if>

</body>
</html>