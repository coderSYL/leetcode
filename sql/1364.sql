# MySQL
# leetcode 1364
# https://leetcode.cn/problems/number-of-trusted-contacts-of-a-customer/

SELECT
    i.invoice_id,
    t2.customer_name,
    i.price,
    t2.contacts_cnt,
    t2.trusted_contacts_cnt
FROM invoices i 
LEFT JOIN (
    SELECT
        c.customer_id AS user_id,
        c.customer_name,
        IFNULL(t1.contacts_cnt, 0) AS contacts_cnt,
        IFNULL(t1.trusted_contacts_cnt, 0) AS trusted_contacts_cnt
    FROM customers c 
    LEFT JOIN (
        SELECT
            c2.user_id,
            COUNT(IF(c1.customer_id = c2.user_id, 1 ,NULL)) AS contacts_cnt,
            COUNT(IF(c1.email = c2.contact_email, 1 ,NULL)) AS trusted_contacts_cnt
        FROM customers c1, contacts c2
        GROUP BY c2.user_id
    ) AS t1 ON c.customer_id = t1.user_id
) AS t2 USING (user_id)
ORDER BY invoice_id;