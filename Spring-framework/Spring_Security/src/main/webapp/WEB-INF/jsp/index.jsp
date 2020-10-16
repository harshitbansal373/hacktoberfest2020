<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core"%>
<%@ taglib uri="http://www.springframework.org/security/tags"
	prefix="security"%>
<%@ page contentType="text/html;charset=UTF-8" language="java"%>
<html>
<body>
	<div style="text-align: center">
		<h1>${title}</h1>
		<h3>
			<c:if test="${pageContext.request.userPrincipal.name != null}">
				<a>Welcome: ${pageContext.request.userPrincipal.name}</a>
				<a href="<c:url value="/perform_logout" />">Logout</a>

				<security:authorize access="hasRole('ROLE_USER')">
					<a href="<c:url value="/user/home" />">User Page</a>
				</security:authorize>

				<security:authorize access="hasRole('ROLE_ADMIN')">
					<a href="<c:url value="/admin/home" />">Admin Page</a>
				</security:authorize>

			</c:if>

			<c:if test="${pageContext.request.userPrincipal.name == null}">
				<a href="<c:url value="/login" />">Login</a>
			</c:if>
		</h3>

		
	</div>
</body>
</html>
